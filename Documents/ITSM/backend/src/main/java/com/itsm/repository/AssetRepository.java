package com.itsm.repository;

import com.itsm.entity.Asset;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import java.util.List;

@Repository
public interface AssetRepository extends JpaRepository<Asset, Long> {
    List<Asset> findByStatus(Asset.Status status);
    List<Asset> findByAssignedToId(Long userId);
}
