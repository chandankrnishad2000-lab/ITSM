package com.itsm.repository;

import com.itsm.entity.ServiceRequest;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import java.util.List;

@Repository
public interface ServiceRequestRepository extends JpaRepository<ServiceRequest, Long> {
    List<ServiceRequest> findByStatus(ServiceRequest.Status status);
    List<ServiceRequest> findByRequestedById(Long userId);
    List<ServiceRequest> findByAssignedToId(Long userId);
}
