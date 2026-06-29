package com.itsm.controller;

import com.itsm.dto.PortalDataResponse;
import com.itsm.service.*;
import lombok.RequiredArgsConstructor;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/portal")
@CrossOrigin(origins = "*")
@RequiredArgsConstructor
public class PortalController {
    private final IncidentService incidentService;
    private final ServiceRequestService serviceRequestService;

    @GetMapping("/data")
    public ResponseEntity<PortalDataResponse> getPortalData() {
        long openIncidents = incidentService.getOpenIncidentsCount();
        long pendingRequests = serviceRequestService.getPendingRequestsCount();

        PortalDataResponse response = PortalDataResponse.builder()
                .build();
        
        return ResponseEntity.ok(response);
    }
}
