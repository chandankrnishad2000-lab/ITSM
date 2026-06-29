# Smart ITSM Portal

A comprehensive IT Service Management portal with modern Vite frontend and Java Spring Boot backend.

## Project Structure

```
ITSM/
├── src/                          # Vite React frontend
│   ├── main.js                  # Entry point with API integration
│   └── styles.css               # Glassmorphism design system
├── index.html                    # Frontend shell
├── package.json                  # Frontend dependencies
├── dist/                         # Built frontend assets
├── backend/                      # Spring Boot backend
│   ├── src/main/java/com/itsm
│   │   ├── controller/          # REST API endpoints
│   │   ├── service/             # Business logic layer
│   │   ├── entity/              # JPA entities
│   │   ├── repository/          # Data access layer
│   │   ├── dto/                 # Data transfer objects
│   │   └── config/              # Spring configuration
│   ├── pom.xml                  # Maven dependencies
│   └── README.md                # Backend documentation
└── README.md                     # This file
```

## Features

### Frontend (Vite + Vanilla JS)
- **Dashboard** - Real-time metrics, SLA compliance, incident queue
- **Incident Management** - Create, track, and resolve IT incidents
- **Service Requests** - Laptop provisioning, software, VPN, email setup
- **Asset Management** - Device inventory and ownership tracking
- **Knowledge Base** - Search FAQs and troubleshooting articles
- **Responsive Design** - Works on desktop and mobile devices
- **API Integration** - Connects to Spring Boot backend with fallback data

### Backend (Spring Boot 3.2)
- **User Authentication** - Role-based access (Employee, Support Engineer, Admin)
- **Incident Management API** - Full CRUD operations with status tracking
- **Service Request Handling** - Automated workflows for common requests
- **Asset Tracking** - Inventory management and assignment history
- **Team Management** - Support team organization and metrics
- **Knowledge Base API** - Search, categorize, and track article usage
- **MySQL Database** - Auto-schema generation with Hibernate
- **CORS Enabled** - Seamless frontend-backend communication
- **Security-Ready** - JWT authentication framework included

## Quick Start

### Frontend Setup

```bash
# Navigate to project root
cd /Users/chandankumar/Documents/ITSM

# Install dependencies
npm install

# Run development server
npm run dev
```

Frontend will be available at `http://localhost:5173`

### Backend Setup

```bash
# Navigate to backend directory
cd /Users/chandankumar/Documents/ITSM/backend

# Install dependencies
mvn clean install

# Run Spring Boot application
mvn spring-boot:run
```

Backend will be available at `http://localhost:8080/api`

### Database Setup

Create MySQL database:
```sql
CREATE DATABASE itsm_db;
```

Update `backend/src/main/resources/application.yml`:
```yaml
spring:
  datasource:
    url: jdbc:mysql://localhost:3306/itsm_db
    username: root
    password: your_password
```

## API Integration

Frontend automatically detects the backend via `VITE_ITSM_API_BASE_URL` environment variable:

```bash
# Development
VITE_ITSM_API_BASE_URL=http://localhost:8080/api npm run dev

# Production
VITE_ITSM_API_BASE_URL=https://api.yourdomain.com npm run build
```

If the API is unavailable, the frontend gracefully falls back to bundled sample data.

## Build for Production

### Frontend
```bash
npm run build
```

Outputs to `dist/` directory. Deploy using any static host (Netlify, Vercel, AWS S3, etc.)

### Backend
```bash
cd backend
mvn clean package
java -jar target/itsm-portal-backend-1.0.0.jar
```

## API Documentation

See `backend/README.md` for complete REST API documentation including:
- User endpoints
- Incident management
- Service requests
- Asset tracking
- Team management
- Knowledge base search

## Technology Stack

### Frontend
- Vite (build tool)
- Vanilla JavaScript (no framework)
- HTML5 + CSS3
- Responsive design system

### Backend
- Java 17
- Spring Boot 3.2
- Spring Data JPA
- Spring Security
- JWT authentication
- MySQL 8.0
- Maven

## Development Workflow

1. **Start Backend** - `cd backend && mvn spring-boot:run`
2. **Start Frontend** - `npm run dev`
3. **Make Changes** - Frontend hot-reloads, backend requires restart
4. **Test APIs** - Use Postman or curl against `http://localhost:8080/api`
5. **Commit** - `git add . && git commit -m "your message"`
6. **Push** - `git push origin main`

## Database Schema

Tables auto-created by Hibernate:
- `users` - Employee and admin accounts
- `incidents` - IT tickets with priority and status
- `service_requests` - Software, hardware, access requests
- `assets` - Company hardware and licenses
- `teams` - Support team definitions
- `knowledge_articles` - KB articles with search indexing

## Environment Variables

### Frontend (.env)
```
VITE_ITSM_API_BASE_URL=http://localhost:8080/api
```

### Backend (application.yml)
```yaml
server:
  port: 8080

spring:
  datasource:
    url: jdbc:mysql://localhost:3306/itsm_db
    username: root
    password: your_password

jwt:
  secret: your-256-bit-secret-key
  expiration: 86400000
```

## Troubleshooting

### Frontend won't connect to backend
- Ensure backend is running on port 8080
- Check `VITE_ITSM_API_BASE_URL` is set correctly
- Verify CORS is enabled in `SecurityConfig.java`

### Database connection error
- Verify MySQL is running: `mysql -u root -p`
- Check `application.yml` credentials
- Ensure `itsm_db` database exists

### Port already in use
- Frontend: `npm run dev -- --port 5174`
- Backend: Change `server.port` in `application.yml`

## Production Deployment

### Frontend
Deploy `dist/` folder to any static hosting (Netlify, Vercel, GitHub Pages, AWS S3)

### Backend
```bash
mvn clean package -DskipTests
java -Dspring.profiles.active=prod -jar target/itsm-portal-backend-1.0.0.jar
```

Use environment variables for sensitive configuration in production.

## Contributors

Smart ITSM Portal Development Team

## License

All rights reserved - 2026
