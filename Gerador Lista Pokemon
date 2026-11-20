#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int numero;
    const char *nome;
    const char *tipagem;
    const char *estagio;
} Pokemon;

int main(void) {
    const Pokemon catalogo[] = {
        {1, "Bulbasaur", "Grass/Poison", "Inicial"},
        {2, "Ivysaur", "Grass/Poison", "Intermediario"},
        {3, "Venusaur", "Grass/Poison", "Final"},
        {4, "Charmander", "Fire", "Inicial"},
        {5, "Charmeleon", "Fire", "Intermediario"},
        {6, "Charizard", "Fire/Flying", "Final"},
        {7, "Squirtle", "Water", "Inicial"},
        {8, "Wartortle", "Water", "Intermediario"},
        {9, "Blastoise", "Water", "Final"},
        {10, "Caterpie", "Bug", "Inicial"},
        {11, "Metapod", "Bug", "Intermediario"},
        {12, "Butterfree", "Bug/Flying", "Final"},
        {13, "Weedle", "Bug/Poison", "Inicial"},
        {14, "Kakuna", "Bug/Poison", "Intermediario"},
        {15, "Beedrill", "Bug/Poison", "Final"},
        {16, "Pidgey", "Normal/Flying", "Inicial"},
        {17, "Pidgeotto", "Normal/Flying", "Intermediario"},
        {18, "Pidgeot", "Normal/Flying", "Final"},
        {19, "Rattata", "Normal", "Inicial"},
        {20, "Raticate", "Normal", "Final"},
        {21, "Spearow", "Normal/Flying", "Inicial"},
        {22, "Fearow", "Normal/Flying", "Final"},
        {23, "Ekans", "Poison", "Inicial"},
        {24, "Arbok", "Poison", "Final"},
        {25, "Pikachu", "Electric", "Intermediario"},
        {26, "Raichu", "Electric", "Final"},
        {27, "Sandshrew", "Ground", "Inicial"},
        {28, "Sandslash", "Ground", "Final"},
        {29, "Nidoran F", "Poison", "Inicial"},
        {30, "Nidorina", "Poison", "Intermediario"},
        {31, "Nidoqueen", "Poison/Ground", "Final"},
        {32, "Nidoran M", "Poison", "Inicial"},
        {33, "Nidorino", "Poison", "Intermediario"},
        {34, "Nidoking", "Poison/Ground", "Final"},
        {35, "Clefairy", "Fairy", "Intermediario"},
        {36, "Clefable", "Fairy", "Final"},
        {37, "Vulpix", "Fire", "Inicial"},
        {38, "Ninetales", "Fire", "Final"},
        {39, "Jigglypuff", "Normal/Fairy", "Intermediario"},
        {40, "Wigglytuff", "Normal/Fairy", "Final"},
        {41, "Zubat", "Poison/Flying", "Inicial"},
        {42, "Golbat", "Poison/Flying", "Intermediario"},
        {43, "Oddish", "Grass/Poison", "Inicial"},
        {44, "Gloom", "Grass/Poison", "Intermediario"},
        {45, "Vileplume", "Grass/Poison", "Final"},
        {46, "Paras", "Bug/Grass", "Inicial"},
        {47, "Parasect", "Bug/Grass", "Final"},
        {48, "Venonat", "Bug/Poison", "Inicial"},
        {49, "Venomoth", "Bug/Poison", "Final"},
        {50, "Diglett", "Ground", "Inicial"},
        {51, "Dugtrio", "Ground", "Final"},
        {52, "Meowth", "Normal", "Inicial"},
        {53, "Persian", "Normal", "Final"},
        {54, "Psyduck", "Water", "Inicial"},
        {55, "Golduck", "Water", "Final"},
        {56, "Mankey", "Fighting", "Inicial"},
        {57, "Primeape", "Fighting", "Intermediario"},
        {58, "Growlithe", "Fire", "Inicial"},
        {59, "Arcanine", "Fire", "Final"},
        {60, "Poliwag", "Water", "Inicial"},
        {61, "Poliwhirl", "Water", "Intermediario"},
        {62, "Poliwrath", "Water/Fighting", "Final"},
        {63, "Abra", "Psychic", "Inicial"},
        {64, "Kadabra", "Psychic", "Intermediario"},
        {65, "Alakazam", "Psychic", "Final"},
        {66, "Machop", "Fighting", "Inicial"},
        {67, "Machoke", "Fighting", "Intermediario"},
        {68, "Machamp", "Fighting", "Final"},
        {69, "Bellsprout", "Grass/Poison", "Inicial"},
        {70, "Weepinbell", "Grass/Poison", "Intermediario"},
        {71, "Victreebel", "Grass/Poison", "Final"},
        {72, "Tentacool", "Water/Poison", "Inicial"},
        {73, "Tentacruel", "Water/Poison", "Final"},
        {74, "Geodude", "Rock/Ground", "Inicial"},
        {75, "Graveler", "Rock/Ground", "Intermediario"},
        {76, "Golem", "Rock/Ground", "Final"},
        {77, "Ponyta", "Fire", "Inicial"},
        {78, "Rapidash", "Fire", "Final"},
        {79, "Slowpoke", "Water/Psychic", "Inicial"},
        {80, "Slowbro", "Water/Psychic", "Final"},
        {81, "Magnemite", "Electric/Steel", "Inicial"},
        {82, "Magneton", "Electric/Steel", "Intermediario"},
        {83, "Farfetchd", "Normal/Flying", "Inicial"},
        {84, "Doduo", "Normal/Flying", "Inicial"},
        {85, "Dodrio", "Normal/Flying", "Final"},
        {86, "Seel", "Water", "Inicial"},
        {87, "Dewgong", "Water/Ice", "Final"},
        {88, "Grimer", "Poison", "Inicial"},
        {89, "Muk", "Poison", "Final"},
        {90, "Shellder", "Water", "Inicial"},
        {91, "Cloyster", "Water/Ice", "Final"},
        {92, "Gastly", "Ghost/Poison", "Inicial"},
        {93, "Haunter", "Ghost/Poison", "Intermediario"},
        {94, "Gengar", "Ghost/Poison", "Final"},
        {95, "Onix", "Rock/Ground", "Inicial"},
        {96, "Drowzee", "Psychic", "Inicial"},
        {97, "Hypno", "Psychic", "Final"},
        {98, "Krabby", "Water", "Inicial"},
        {99, "Kingler", "Water", "Final"},
        {100, "Voltorb", "Electric", "Inicial"},
        {101, "Electrode", "Electric", "Final"},
        {102, "Exeggcute", "Grass/Psychic", "Inicial"},
        {103, "Exeggutor", "Grass/Psychic", "Final"},
        {104, "Cubone", "Ground", "Inicial"},
        {105, "Marowak", "Ground", "Final"},
        {106, "Hitmonlee", "Fighting", "Final"},
        {107, "Hitmonchan", "Fighting", "Final"},
        {108, "Lickitung", "Normal", "Inicial"},
        {109, "Koffing", "Poison", "Inicial"},
        {110, "Weezing", "Poison", "Final"},
        {111, "Rhyhorn", "Ground/Rock", "Inicial"},
        {112, "Rhydon", "Ground/Rock", "Intermediario"},
        {113, "Chansey", "Normal", "Intermediario"},
        {114, "Tangela", "Grass", "Inicial"},
        {115, "Kangaskhan", "Normal", "Unico"},
        {116, "Horsea", "Water", "Inicial"},
        {117, "Seadra", "Water", "Intermediario"},
        {118, "Goldeen", "Water", "Inicial"},
        {119, "Seaking", "Water", "Final"},
        {120, "Staryu", "Water", "Inicial"},
        {121, "Starmie", "Water/Psychic", "Final"},
        {122, "Mr. Mime", "Psychic/Fairy", "Final"},
        {123, "Scyther", "Bug/Flying", "Inicial"},
        {124, "Jynx", "Ice/Psychic", "Final"},
        {125, "Electabuzz", "Electric", "Intermediario"},
        {126, "Magmar", "Fire", "Intermediario"},
        {127, "Pinsir", "Bug", "Unico"},
        {128, "Tauros", "Normal", "Unico"},
        {129, "Magikarp", "Water", "Inicial"},
        {130, "Gyarados", "Water/Flying", "Final"},
        {131, "Lapras", "Water/Ice", "Unico"},
        {132, "Ditto", "Normal", "Unico"},
        {133, "Eevee", "Normal", "Inicial"},
        {134, "Vaporeon", "Water", "Final"},
        {135, "Jolteon", "Electric", "Final"},
        {136, "Flareon", "Fire", "Final"},
        {137, "Porygon", "Normal", "Inicial"},
        {138, "Omanyte", "Rock/Water", "Inicial"},
        {139, "Omastar", "Rock/Water", "Final"},
        {140, "Kabuto", "Rock/Water", "Inicial"},
        {141, "Kabutops", "Rock/Water", "Final"},
        {142, "Aerodactyl", "Rock/Flying", "Unico"},
        {143, "Snorlax", "Normal", "Final"},
        {144, "Articuno", "Ice/Flying", "Unico"},
        {145, "Zapdos", "Electric/Flying", "Unico"},
        {146, "Moltres", "Fire/Flying", "Unico"},
        {147, "Dratini", "Dragon", "Inicial"},
        {148, "Dragonair", "Dragon", "Intermediario"},
        {149, "Dragonite", "Dragon/Flying", "Final"},
        {150, "Mewtwo", "Psychic", "Unico"},
        {151, "Mew", "Psychic", "Unico"}
    };
    const int quantidade = 151;
    const int total = (int)(sizeof(catalogo) / sizeof(catalogo[0]));
    int indices[sizeof(catalogo) / sizeof(catalogo[0])];
    int i, j, temporario;
    FILE *arquivo;

    srand((unsigned int)time(NULL));

    for (i = 0; i < total; i++) {
        indices[i] = i;
    }

    for (i = total - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temporario = indices[i];
        indices[i] = indices[j];
        indices[j] = temporario;
    }

    arquivo = fopen("pokemons.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar pokemons.txt\n");
        return 1;
    }

    if (fprintf(arquivo, "numero;nome;tipagem;estagio\n") < 0) {
        printf("Erro ao escrever o cabecalho.\n");
        fclose(arquivo);
        return 1;
    }

    printf("Lista dos %d Pokemons:\n", quantidade);
    printf("numero;nome;tipagem;estagio\n");

    for (i = 0; i < quantidade; i++) {
        const Pokemon *p = &catalogo[indices[i]];
        if (fprintf(arquivo, "%04d;%s;%s;%s\n",
                    p->numero, p->nome, p->tipagem, p->estagio) < 0) {
            printf("Erro ao gravar os dados no arquivo.\n");
            fclose(arquivo);
            return 1;
        }
        printf("%04d;%s;%s;%s\n",
               p->numero, p->nome, p->tipagem, p->estagio);
    }

    if (fclose(arquivo) != 0) {
        printf("Erro ao fechar o arquivo.\n");
        return 1;
    }

    printf("Arquivo pokemons.txt criado com %d Pokemons diferentes!\n", quantidade);
    printf("Catalogo carregado com os 151 primeiros Pokemons.\n");
    return 0;
}
