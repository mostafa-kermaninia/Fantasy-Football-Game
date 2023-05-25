#include "FutballFantasy.hpp"

main(int argc, char *argv[])
{
    FutballFantasy Futball_Fantasy(argv[LEAGUE_FILE_PATH_INDEX]);
    Futball_Fantasy.run();
}
