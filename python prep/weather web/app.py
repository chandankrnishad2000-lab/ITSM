import os
import requests
from flask import Flask, render_template, request, session

app = Flask(__name__)
app.secret_key = 'supersecretkey'  # Needed for session

API_KEY = os.getenv("OPENWEATHER_API_KEY", "YOUR_API_KEY")

def get_weather(city):
    url = f"https://api.openweathermap.org/data/2.5/weather?q={city}&appid={API_KEY}&units=metric"
    res = requests.get(url)
    if res.status_code == 200:
        data = res.json()
        return {
            "city": data["name"],
            "temperature": data["main"]["temp"],
            "description": data["weather"][0]["description"].title(),
            "icon": data["weather"][0]["icon"],
            "humidity": data["main"]["humidity"],
            "wind": data["wind"]["speed"],
            "main": data["weather"][0]["main"],
        }
    return None

@app.route("/", methods=["GET", "POST"])
def index():
    weather = None
    error = None
    if "history" not in session:
        session["history"] = []
    if request.method == "POST":
        city = request.form.get("city")
        if city:
            weather = get_weather(city)
            if weather:
                # Add to search history, avoid duplicates
                history = session["history"]
                if weather["city"] not in history:
                    history.insert(0, weather["city"])
                    if len(history) > 5: history = history[:5]
                session["history"] = history
            else:
                error = "City not found or API error."
        else:
            error = "Please enter a city name."
    history = session.get("history", [])
    return render_template("index.html", weather=weather, error=error, history=history)

if __name__ == "__main__":
    app.run(debug=True)