# Weather Web Application

A simple Python Flask app to display current weather information for a city using the OpenWeatherMap API.

## Instructions

1. **Clone this repo**  
2. **Get a free API key** from [OpenWeatherMap](https://openweathermap.org/api)  
3. **Set your API key** as an environment variable:
    ```
    export OPENWEATHER_API_KEY=your_api_key_here
    ```

4. **Install dependencies:**
    ```
    pip install -r requirements.txt
    ```

5. **Run the app:**
    ```
    python app.py
    ```
    Visit [http://localhost:5000](http://localhost:5000) in your browser.

## Features

- Enter a city name and get live weather updates
- Shows temperature, condition, and icon
- Error handling for wrong input or failed API request

Feel free to modify and enhance!