package com.itsm.service;

import com.itsm.entity.ServiceRequest;
import com.itsm.repository.ServiceRequestRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import java.util.List;
import java.util.Optional;
import java.util.UUID;

@Service
@RequiredArgsConstructor
public class ServiceRequestService {
    private final ServiceRequestRepository serviceRequestRepository;

    public ServiceRequest createServiceRequest(ServiceRequest serviceRequest) {
        serviceRequest.setRequestId("SR-" + UUID.randomUUID().toString().substring(0, 8).toUpperCase());
        return serviceRequestRepository.save(serviceRequest);
    }

    public Optional<ServiceRequest> findById(Long id) {
        return serviceRequestRepository.findById(id);
    }

    public List<ServiceRequest> getAllServiceRequests() {
        return serviceRequestRepository.findAll();
    }

    public List<ServiceRequest> getServiceRequestsByStatus(ServiceRequest.Status status) {
        return serviceRequestRepository.findByStatus(status);
    }

    public List<ServiceRequest> getServiceRequestsBy(Long userId) {
        return serviceRequestRepository.findByRequestedById(userId);
    }

    public List<ServiceRequest> getServiceRequestsAssignedTo(Long userId) {
        return serviceRequestRepository.findByAssignedToId(userId);
    }

    public ServiceRequest updateServiceRequest(ServiceRequest serviceRequest) {
        return serviceRequestRepository.save(serviceRequest);
    }

    public void deleteServiceRequest(Long id) {
        serviceRequestRepository.deleteById(id);
    }

    public long getPendingRequestsCount() {
        return getServiceRequestsByStatus(ServiceRequest.Status.PENDING).size();
    }
}
