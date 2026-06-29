package com.itsm.dto;

import lombok.*;

@Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
public class PortalDataResponse {
    private MetricsDTO metrics;
    private java.util.List<IncidentDTO> queue;
    private java.util.List<java.util.List<String>> requests;
    private java.util.List<java.util.List<String>> assets;
    private java.util.List<java.util.List<String>> employees;
    private java.util.List<java.util.List<String>> teams;
}

@Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
class MetricsDTO {
    private int openIncidents;
    private int pendingRequests;
    private int slaRisk;
    private String serviceHealth;
    private String serviceHealthDetail;
    private String workflowFocus;
    private String workflowFocusDetail;
    private String assetControl;
    private String assetControlDetail;
}

@Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
class IncidentDTO {
    private String id;
    private String title;
    private String owner;
    private String priority;
    private String status;
    private String detail;
}
