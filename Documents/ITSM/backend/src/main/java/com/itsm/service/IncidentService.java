package com.itsm.service;

import com.itsm.entity.Incident;
import com.itsm.repository.IncidentRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import java.util.List;
import java.util.Optional;
import java.util.UUID;

@Service
@RequiredArgsConstructor
public class IncidentService {
    private final IncidentRepository incidentRepository;

    public Incident createIncident(Incident incident) {
        incident.setIncidentId("INC-" + UUID.randomUUID().toString().substring(0, 8).toUpperCase());
        return incidentRepository.save(incident);
    }

    public Optional<Incident> findById(Long id) {
        return incidentRepository.findById(id);
    }

    public List<Incident> getAllIncidents() {
        return incidentRepository.findAll();
    }

    public List<Incident> getIncidentsByStatus(Incident.Status status) {
        return incidentRepository.findByStatus(status);
    }

    public List<Incident> getIncidentsReportedBy(Long userId) {
        return incidentRepository.findByReportedById(userId);
    }

    public List<Incident> getIncidentsAssignedTo(Long userId) {
        return incidentRepository.findByAssignedToId(userId);
    }

    public Incident updateIncident(Incident incident) {
        return incidentRepository.save(incident);
    }

    public void deleteIncident(Long id) {
        incidentRepository.deleteById(id);
    }

    public long getOpenIncidentsCount() {
        return getIncidentsByStatus(Incident.Status.OPEN).size();
    }
}
