#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

// Ovde se ne smeju slati reference jer ne zelimo da menjamo originalne nizove
// Takodje, ako bi se slale const promenljive, sortiranje ne bi bilo moguce
int najmanja_razlika(std::vector<int> marija_cene, std::vector<int> petar_cene)
{
    // Soritramo nizove cena za oboje
    std::sort(marija_cene.begin(), marija_cene.end());
    std::sort(petar_cene.begin(), petar_cene.end());

    // Posto trazimo neki minimum, najbolje je da za pocetnu vrednost minimuma uzmemo INT_MAX
    int min_razlika = INT_MAX /*INT_MIN*/, trenutna_razlika;

    int i = 0, j = 0, n = marija_cene.size(), m = petar_cene.size();

    // Prolazimo kroz oba niza paralelno, slicno kao u algoritmu merge sort u koraku objedinjavanja
    while (i < n && j < m) {
        // Racunamo za 2 odgovarajuca elementa razliku u cenama
        trenutna_razlika = std::abs(marija_cene[i] - petar_cene[j]);

        // I ako je ona manja od do tada minimalne razlike, azuriramo minimum
        if (trenutna_razlika < min_razlika) {
            min_razlika = trenutna_razlika;
        }

        // Ako se desi da je cena Marijinog poklona manja od cene Petrovog poklona, ovaj Marijin poklon dalje nema smisla
        // razmatrati. Razlika izmedju njega i svih ostalih Petrovih poklona mora sigurno biti veca od razlike ovog poklona
        // i trenutnog Petrovog poklona koji se razmatra
        if (marija_cene[i] < petar_cene[j]) {
            i++;
        }
        // Isto vazi i ako je cena Petrovog poklona niza od cene Marijinog poklona
        else if (marija_cene[i] > petar_cene[j]) {
            j++;
        }
        // Ako se desi da su cene poklona jednake, onda je minimalna razlika 0, sto je i najmanje moguce, pa se odmah izlazi iz funkcije
        // jer nema potrebe dalje ici (mini optimizacija)
        else {
            return 0;
        }
    }

    // Na kraju kada nadjemo minimalnu razliku (koja nije 0), vracamo tu vrednost
    return min_razlika;
}

int main ()
{
    std::vector<int> petar_cene = {1, 33, 28, 14, 45};
    std::vector<int> marija_cene = {22, 8, 21, 56, 41, 68};

    std::cout << najmanja_razlika(marija_cene, petar_cene) << "\n";

    return 0;
}