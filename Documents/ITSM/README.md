# Smart ITSM Portal

A Vite-powered IT service management portal for incidents, service requests, assets, employees, and support teams.

## What’s included

- Dashboard summary and SLA snapshot
- Incident queue with priority badges
- Service request, asset, employee, and team views
- Responsive layout for desktop and mobile
- API-ready data loading with local fallback content

## Run locally

```bash
npm install
npm run dev
```

Then open the local Vite URL shown in the terminal.

## Optional API hookup

Set `VITE_ITSM_API_BASE_URL` to point at a backend that serves `GET /portal-data`.

Example:

```bash
VITE_ITSM_API_BASE_URL=https://api.example.com
```

If the API is unavailable, the app falls back to bundled sample data.
