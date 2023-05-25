#include <iostream>
#include <string>
#include "Composition.h"
const int MAX_COMPOSITIONS = 100;

class ArtExhibition {
private:
    Composition catalog[MAX_COMPOSITIONS];
    int compositionCount;
    int voteStatistics[MAX_COMPOSITIONS];

public:
    ArtExhibition() : compositionCount(0) {
        for (int i = 0; i < MAX_COMPOSITIONS; ++i) {
            voteStatistics[i] = 0;
        }
    }

    void insertComposition(int index, const std::string& artist, const std::string& title, const std::string& category) {
        if (index < 0 || index > compositionCount || compositionCount == MAX_COMPOSITIONS) {
            std::cout << "Inserarea compozitiei nu este posibila!" << std::endl;
            return;
        }

        for (int i = compositionCount; i > index; --i) {
            catalog[i] = catalog[i - 1];
        }

        Composition composition;
        composition.artist = artist;
        composition.title = title;
        composition.category = category;

        catalog[index] = composition;
        compositionCount++;
    }

    void voteComposition(const std::string& title) {
        for (int i = 0; i < compositionCount; ++i) {
            if (catalog[i].title == title) {
                catalog[i].votes++;
                voteStatistics[i]++;
                return;
            }
        }

        std::cout << "Compozitia nu a fost gasita in catalog!" << std::endl;
    }

    void displayVoteStatistics() {
        std::cout << "Statistica voturilor:" << std::endl;
        for (int i = 0; i < compositionCount; ++i) {
            std::cout << catalog[i].category << ": " << voteStatistics[i] << " voturi" << std::endl;
        }
    }

    int countAcceptedCompositions(const std::string& category, const std::string& artist) {
        int count = 0;
        for (int i = 0; i < compositionCount; ++i) {
            if (catalog[i].category == category && catalog[i].artist == artist) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    ArtExhibition exhibition;

    exhibition.insertComposition(0, "Artist1", "Compozitie1", "Categoria1");
    exhibition.insertComposition(1, "Artist2", "Compozitie2", "Categoria2");
    exhibition.insertComposition(2, "Artist3", "Compozitie3", "Categoria1");
    exhibition.insertComposition(3, "Artist4", "Compozitie4", "Categoria3");

    exhibition.voteComposition("Compozitie1");
    exhibition.voteComposition("Compozitie1");
    exhibition.voteComposition("Compozitie2");
    exhibition.voteComposition("Compozitie3");
    exhibition.voteComposition("Compozitie4");
    exhibition.voteComposition("Compozitie4");
    exhibition.voteComposition("Compozitie4");

    exhibition.displayVoteStatistics();

    int acceptedCount = exhibition.countAcceptedCompositions("Categoria1", "Artist1");
    std::cout << "Numarul de obiecte de arta acceptate: " << acceptedCount << std::endl;

    return 0;
}
