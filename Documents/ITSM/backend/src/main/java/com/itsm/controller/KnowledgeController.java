package com.itsm.controller;

import com.itsm.entity.KnowledgeArticle;
import com.itsm.service.KnowledgeService;
import lombok.RequiredArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import java.util.List;

@RestController
@RequestMapping("/knowledge")
@CrossOrigin(origins = "*")
@RequiredArgsConstructor
public class KnowledgeController {
    private final KnowledgeService knowledgeService;

    @GetMapping
    public ResponseEntity<List<KnowledgeArticle>> getAllArticles() {
        return ResponseEntity.ok(knowledgeService.getAllArticles());
    }

    @GetMapping("/{id}")
    public ResponseEntity<KnowledgeArticle> getArticleById(@PathVariable Long id) {
        knowledgeService.incrementViewCount(id);
        return knowledgeService.findById(id)
                .map(ResponseEntity::ok)
                .orElse(ResponseEntity.notFound().build());
    }

    @GetMapping("/search")
    public ResponseEntity<List<KnowledgeArticle>> searchArticles(@RequestParam String q) {
        return ResponseEntity.ok(knowledgeService.searchByTitle(q));
    }

    @GetMapping("/category/{category}")
    public ResponseEntity<List<KnowledgeArticle>> getArticlesByCategory(@PathVariable String category) {
        return ResponseEntity.ok(knowledgeService.getByCategory(category));
    }

    @PostMapping
    public ResponseEntity<KnowledgeArticle> createArticle(@RequestBody KnowledgeArticle article) {
        KnowledgeArticle createdArticle = knowledgeService.createArticle(article);
        return ResponseEntity.status(HttpStatus.CREATED).body(createdArticle);
    }

    @PutMapping("/{id}")
    public ResponseEntity<KnowledgeArticle> updateArticle(@PathVariable Long id, @RequestBody KnowledgeArticle articleDetails) {
        return knowledgeService.findById(id).map(article -> {
            if (articleDetails.getTitle() != null) article.setTitle(articleDetails.getTitle());
            if (articleDetails.getContent() != null) article.setContent(articleDetails.getContent());
            if (articleDetails.getCategory() != null) article.setCategory(articleDetails.getCategory());
            return ResponseEntity.ok(knowledgeService.updateArticle(article));
        }).orElse(ResponseEntity.notFound().build());
    }

    @DeleteMapping("/{id}")
    public ResponseEntity<Void> deleteArticle(@PathVariable Long id) {
        knowledgeService.deleteArticle(id);
        return ResponseEntity.noContent().build();
    }
}
