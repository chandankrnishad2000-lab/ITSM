import "./styles.css";

const apiBaseUrl = import.meta.env.VITE_ITSM_API_BASE_URL || "";

const fallbackData = {
  metrics: {
    openIncidents: 18,
    pendingRequests: 12,
    slaRisk: 4,
    serviceHealth: "92% SLA compliance",
    serviceHealthDetail: "Faster triage, visibility across teams, and clean handoffs.",
    workflowFocus: "Report → Triage → Resolve",
    workflowFocusDetail: "Structured paths for incidents and requests from intake to closure.",
    assetControl: "128 tracked assets",
    assetControlDetail: "Devices, licenses, and ownership mapped to employees and teams.",
  },
  queue: [
    {
      id: "INC-1042",
      title: "VPN connection failures",
      owner: "Lena Patel",
      priority: "High",
      status: "Investigating",
      detail: "Network team engaged; 14 employees affected across two offices.",
    },
    {
      id: "INC-1048",
      title: "Email sync lag on mobile",
      owner: "Derek Wong",
      priority: "Medium",
      status: "In progress",
      detail: "Device resets completed; awaiting mailbox policy refresh.",
    },
    {
      id: "SR-2091",
      title: "New software access request",
      owner: "Ava Johnson",
      priority: "Low",
      status: "Pending approval",
      detail: "Manager approval required before provisioning license.",
    },
  ],
  requests: [
    ["Onboard laptop setup", "Provision laptop, account access, and standard apps."],
    ["Password reset", "Automated identity verification with self-service unlock."],
    ["Software installation", "Controlled app catalog with approval gates."],
  ],
  assets: [
    ["MacBook Pro - ENG-014", "Assigned to Mia Chen · Healthy"],
    ["Surface Laptop - HR-028", "Assigned to Samir Khan · Due for refresh"],
    ["iPhone 15 - MOB-112", "Assigned to Priya Das · In repair"],
  ],
  employees: [
    ["Mia Chen", "Engineering · 2 open tickets · 1 pending request"],
    ["Samir Khan", "HR · 0 open tickets · latest asset audit complete"],
    ["Priya Das", "Operations · 1 open ticket · waiting on hardware swap"],
  ],
  teams: [
    ["Service Desk", "First-line support for incidents and requests"],
    ["Endpoint Engineering", "Assets, imaging, and device compliance"],
    ["Identity & Access", "Accounts, permissions, and access reviews"],
  ],
};

const dom = {
  openIncidents: document.getElementById("openIncidents"),
  pendingRequests: document.getElementById("pendingRequests"),
  slaRisk: document.getElementById("slaRisk"),
  serviceHealth: document.getElementById("serviceHealth"),
  serviceHealthDetail: document.getElementById("serviceHealthDetail"),
  workflowFocus: document.getElementById("workflowFocus"),
  workflowFocusDetail: document.getElementById("workflowFocusDetail"),
  assetControl: document.getElementById("assetControl"),
  assetControlDetail: document.getElementById("assetControlDetail"),
  queueList: document.getElementById("queueList"),
  requestList: document.getElementById("requestList"),
  assetList: document.getElementById("assetList"),
  employeeList: document.getElementById("employeeList"),
  teamList: document.getElementById("teamList"),
};

async function loadPortalData() {
  if (!apiBaseUrl) {
    return fallbackData;
  }

  try {
    const response = await fetch(`${apiBaseUrl.replace(/\/$/, "")}/portal-data`);
    if (!response.ok) {
      throw new Error(`Request failed with ${response.status}`);
    }

    return await response.json();
  } catch (error) {
    console.warn("Falling back to bundled portal data:", error);
    return fallbackData;
  }
}

function badgeClass(priority) {
  return priority.toLowerCase();
}

function renderQueue(queue) {
  dom.queueList.innerHTML = queue
    .map(
      (ticket) => `
        <article class="ticket-item">
          <div class="heading">
            <div>
              <strong>${ticket.id} · ${ticket.title}</strong>
              <div class="meta">Owner: ${ticket.owner}</div>
            </div>
            <span class="badge ${badgeClass(ticket.priority)}">${ticket.priority}</span>
          </div>
          <div class="meta">${ticket.detail}</div>
          <div class="meta">Status: ${ticket.status}</div>
        </article>
      `,
    )
    .join("");
}

function renderSimpleList(target, items) {
  target.innerHTML = items
    .map(
      ([title, meta]) => `
        <article class="simple-item">
          <div class="heading">
            <strong>${title}</strong>
          </div>
          <div class="meta">${meta}</div>
        </article>
      `,
    )
    .join("");
}

function wireNav() {
  const navItems = document.querySelectorAll(".nav-item");
  navItems.forEach((item) => {
    item.addEventListener("click", () => {
      navItems.forEach((button) => button.classList.remove("active"));
      item.classList.add("active");
    });
  });
}

function applyMetrics(metrics) {
  dom.openIncidents.textContent = metrics.openIncidents;
  dom.pendingRequests.textContent = metrics.pendingRequests;
  dom.slaRisk.textContent = metrics.slaRisk;
  dom.serviceHealth.textContent = metrics.serviceHealth;
  dom.serviceHealthDetail.textContent = metrics.serviceHealthDetail;
  dom.workflowFocus.textContent = metrics.workflowFocus;
  dom.workflowFocusDetail.textContent = metrics.workflowFocusDetail;
  dom.assetControl.textContent = metrics.assetControl;
  dom.assetControlDetail.textContent = metrics.assetControlDetail;
}

async function init() {
  const data = await loadPortalData();
  applyMetrics(data.metrics);
  renderQueue(data.queue);
  renderSimpleList(dom.requestList, data.requests);
  renderSimpleList(dom.assetList, data.assets);
  renderSimpleList(dom.employeeList, data.employees);
  renderSimpleList(dom.teamList, data.teams);
  wireNav();
}

init();
