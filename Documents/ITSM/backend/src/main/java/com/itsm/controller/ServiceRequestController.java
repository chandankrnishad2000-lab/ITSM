package com.itsm.controller;

import com.itsm.entity.ServiceRequest;
import com.itsm.service.ServiceRequestService;
import lombok.RequiredArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import java.util.List;

@RestController
@RequestMapping("/service-requests")
@CrossOrigin(origins = "*")
@RequiredArgsConstructor
public class ServiceRequestController {
    private final ServiceRequestService serviceRequestService;

    @GetMapping
    public ResponseEntity<List<ServiceRequest>> getAllRequests() {
        return ResponseEntity.ok(serviceRequestService.getAllServiceRequests());
    }

    @GetMapping("/{id}")
    public ResponseEntity<ServiceRequest> getRequestById(@PathVariable Long id) {
        return serviceRequestService.findById(id)
                .map(ResponseEntity::ok)
                .orElse(ResponseEntity.notFound().build());
    }

    @GetMapping("/status/{status}")
    public ResponseEntity<List<ServiceRequest>> getRequestsByStatus(@PathVariable String status) {
        return ResponseEntity.ok(serviceRequestService.getServiceRequestsByStatus(ServiceRequest.Status.valueOf(status)));
    }

    @PostMapping
    public ResponseEntity<ServiceRequest> createRequest(@RequestBody ServiceRequest serviceRequest) {
        ServiceRequest createdRequest = serviceRequestService.createServiceRequest(serviceRequest);
        return ResponseEntity.status(HttpStatus.CREATED).body(createdRequest);
    }

    @PutMapping("/{id}")
    public ResponseEntity<ServiceRequest> updateRequest(@PathVariable Long id, @RequestBody ServiceRequest requestDetails) {
        return serviceRequestService.findById(id).map(request -> {
            if (requestDetails.getTitle() != null) request.setTitle(requestDetails.getTitle());
            if (requestDetails.getDescription() != null) request.setDescription(requestDetails.getDescription());
            if (requestDetails.getStatus() != null) request.setStatus(requestDetails.getStatus());
            if (requestDetails.getType() != null) request.setType(requestDetails.getType());
            return ResponseEntity.ok(serviceRequestService.updateServiceRequest(request));
        }).orElse(ResponseEntity.notFound().build());
    }

    @DeleteMapping("/{id}")
    public ResponseEntity<Void> deleteRequest(@PathVariable Long id) {
        serviceRequestService.deleteServiceRequest(id);
        return ResponseEntity.noContent().build();
    }
}
