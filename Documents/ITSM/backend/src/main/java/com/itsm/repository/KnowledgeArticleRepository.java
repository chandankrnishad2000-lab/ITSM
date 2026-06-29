package com.itsm.repository;

import com.itsm.entity.KnowledgeArticle;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import java.util.List;

@Repository
public interface KnowledgeArticleRepository extends JpaRepository<KnowledgeArticle, Long> {
    List<KnowledgeArticle> findByTitleContainingIgnoreCase(String title);
    List<KnowledgeArticle> findByCategory(String category);
}
