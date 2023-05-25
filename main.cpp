#include "FutballFantasy.hpp"


main(int argc, char *argv[])
{
    FutballFantasy Futball_Fantasy(argv[WEEKS_FOLDER_PATH_INDEX], COUNT_OF_WEEKS, argv[INFO_FILE_PATH_INDEX]);
    Futball_Fantasy.run();
}
