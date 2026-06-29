package com.itsm.service;

import com.itsm.entity.KnowledgeArticle;
import com.itsm.repository.KnowledgeArticleRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import java.util.List;
import java.util.Optional;

@Service
@RequiredArgsConstructor
public class KnowledgeService {
    private final KnowledgeArticleRepository knowledgeArticleRepository;

    public KnowledgeArticle createArticle(KnowledgeArticle article) {
        return knowledgeArticleRepository.save(article);
    }

    public Optional<KnowledgeArticle> findById(Long id) {
        return knowledgeArticleRepository.findById(id);
    }

    public List<KnowledgeArticle> getAllArticles() {
        return knowledgeArticleRepository.findAll();
    }

    public List<KnowledgeArticle> searchByTitle(String title) {
        return knowledgeArticleRepository.findByTitleContainingIgnoreCase(title);
    }

    public List<KnowledgeArticle> getByCategory(String category) {
        return knowledgeArticleRepository.findByCategory(category);
    }

    public KnowledgeArticle updateArticle(KnowledgeArticle article) {
        return knowledgeArticleRepository.save(article);
    }

    public void deleteArticle(Long id) {
        knowledgeArticleRepository.deleteById(id);
    }

    public KnowledgeArticle incrementViewCount(Long id) {
        return findById(id).map(article -> {
            article.setViewCount(article.getViewCount() + 1);
            return updateArticle(article);
        }).orElse(null);
    }
}
