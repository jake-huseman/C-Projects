#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *words[] =
        {
        "apple" ,
        "boring" ,
        "cravat",
        "dinosaur",
        "eccentric",
        "fornicate",
        "grasshopper",
        "health",
        "iguana",
        "juxtapose",
        "khaki",
        "limousine",
        "microwave",
        "nuance",
        "ovoid",
        "pterodactyl",
        "quizzical",
        "rambunctious",
        "supercalifragilisticexpialidocious",
        "trex",
        "underwhelming",
        "violent",
        "wherewithal",
        "xylophone",
        "y",
        "zoological",

};

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage: %s <character>\n", argv[0]);

        return 1;
    }

    printf("%c is for %s\n", argv[1][0], words[tolower(argv[1][0])] - 'a'); // instead of a, -97. if you want.
    // argv[1][0]first letter off the word or just the letter depending on what they type.
    // Ascii table for letter to num which is 'a' for.

    return 0;
}
// usage ./char <character>
// a is 97 so on
// b is 98
// char c = 'a'; // c = 97
// capital letters may break because negative num.
// will give whatever is in mem might be null or break.
// fix by making to lower case.