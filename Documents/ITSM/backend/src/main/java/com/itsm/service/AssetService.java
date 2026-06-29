package com.itsm.service;

import com.itsm.entity.Asset;
import com.itsm.repository.AssetRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import java.util.List;
import java.util.Optional;
import java.util.UUID;

@Service
@RequiredArgsConstructor
public class AssetService {
    private final AssetRepository assetRepository;

    public Asset createAsset(Asset asset) {
        asset.setAssetId("AST-" + UUID.randomUUID().toString().substring(0, 8).toUpperCase());
        return assetRepository.save(asset);
    }

    public Optional<Asset> findById(Long id) {
        return assetRepository.findById(id);
    }

    public List<Asset> getAllAssets() {
        return assetRepository.findAll();
    }

    public List<Asset> getAssetsByStatus(Asset.Status status) {
        return assetRepository.findByStatus(status);
    }

    public List<Asset> getAssetsAssignedTo(Long userId) {
        return assetRepository.findByAssignedToId(userId);
    }

    public Asset updateAsset(Asset asset) {
        return assetRepository.save(asset);
    }

    public void deleteAsset(Long id) {
        assetRepository.deleteById(id);
    }
}
