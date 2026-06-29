# Smart ITSM Portal - Spring Boot Backend

A comprehensive REST API backend for the Smart ITSM Portal using Spring Boot 3.2, JPA, MySQL, and JWT authentication.

## Features

- **User Authentication & Authorization** - Role-based access (Employee, Support Engineer, Admin)
- **Incident Management** - Create, assign, track, and resolve incidents
- **Service Requests** - Handle various service request types
- **Asset Management** - Track company assets and assignments
- **Team Management** - Organize support teams and coverage
- **Knowledge Base** - Search articles, FAQs, and troubleshooting guides
- **REST APIs** - Fully documented endpoints for all operations

## Prerequisites

- Java 17+
- Maven 3.8+
- MySQL 8.0+

## Setup

1. **Install dependencies:**
   ```bash
   mvn clean install
   ```

2. **Configure database** in `src/main/resources/application.yml`:
   ```yaml
   spring:
     datasource:
       url: jdbc:mysql://localhost:3306/itsm_db
       username: root
       password: your_password
   ```

3. **Run the application:**
   ```bash
   mvn spring-boot:run
   ```

The backend will start on `http://localhost:8080/api`.

## API Endpoints

### Users
- `GET /api/users` - Get all users
- `GET /api/users/{id}` - Get user by ID
- `POST /api/users/register` - Register new user
- `PUT /api/users/{id}` - Update user
- `DELETE /api/users/{id}` - Delete user

### Incidents
- `GET /api/incidents` - Get all incidents
- `GET /api/incidents/{id}` - Get incident by ID
- `GET /api/incidents/status/{status}` - Filter by status
- `POST /api/incidents` - Create incident
- `PUT /api/incidents/{id}` - Update incident
- `DELETE /api/incidents/{id}` - Delete incident

### Service Requests
- `GET /api/service-requests` - Get all requests
- `GET /api/service-requests/{id}` - Get request by ID
- `GET /api/service-requests/status/{status}` - Filter by status
- `POST /api/service-requests` - Create request
- `PUT /api/service-requests/{id}` - Update request
- `DELETE /api/service-requests/{id}` - Delete request

### Assets
- `GET /api/assets` - Get all assets
- `GET /api/assets/{id}` - Get asset by ID
- `GET /api/assets/status/{status}` - Filter by status
- `POST /api/assets` - Create asset
- `PUT /api/assets/{id}` - Update asset
- `DELETE /api/assets/{id}` - Delete asset

### Teams
- `GET /api/teams` - Get all teams
- `GET /api/teams/{id}` - Get team by ID
- `POST /api/teams` - Create team
- `PUT /api/teams/{id}` - Update team
- `DELETE /api/teams/{id}` - Delete team

### Knowledge Base
- `GET /api/knowledge` - Get all articles
- `GET /api/knowledge/{id}` - Get article by ID
- `GET /api/knowledge/search?q=term` - Search articles
- `GET /api/knowledge/category/{category}` - Get by category
- `POST /api/knowledge` - Create article
- `PUT /api/knowledge/{id}` - Update article
- `DELETE /api/knowledge/{id}` - Delete article

### Portal Data
- `GET /api/portal/data` - Get dashboard metrics

## Database Schema

The backend auto-creates tables for:
- `users` - Employee and staff accounts
- `incidents` - IT incidents and tickets
- `service_requests` - Service requests (laptop, software, VPN, etc.)
- `assets` - Company assets (laptops, monitors, licenses)
- `teams` - Support teams
- `knowledge_articles` - Knowledge base articles

## Configuration

### JWT Secret
Change the JWT secret in `application.yml`:
```yaml
jwt:
  secret: your-super-secret-key-min-256-bits
  expiration: 86400000
```

### Database
Update MySQL credentials:
```yaml
spring:
  datasource:
    url: jdbc:mysql://localhost:3306/itsm_db
    username: root
    password: your_password
```

## Build

```bash
mvn clean package
java -jar target/itsm-portal-backend-1.0.0.jar
```

## Integration with Frontend

The frontend should point to `http://localhost:8080/api`.

Set `VITE_ITSM_API_BASE_URL=http://localhost:8080/api` in the frontend environment.

## Technologies

- Spring Boot 3.2
- Spring Data JPA
- Spring Security + JWT
- MySQL 8.0
- Lombok
- Maven

## License

Smart ITSM Portal - All rights reserved
