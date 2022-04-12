# Programming Assignment for Design & Analysis of Algorithms (CSC-310)

## Recommendations

Though I have ways that you can execute the program without using the `.sh` files, it is highly recommened to use them as they will be updated with the best possible plans for execution. Otherwise if you want to explore other ways of doing it, you can use the methods down below.

## Running with Supplied Code.zip and Data.zip

Move both the Code.zip and Data.zip files into the same directory. Unzip both files into that directory using `unzip Code.zip` and `unzip Data.zip`. After unzipping the two files, you can run the tests via `./run_tests.sh`. After the tests are done, you should see a output.csv file. You can open that to explore the results of the test.

## Generation of Data

If you wish to generate the data, please run the `./run_generator.sh` in the terminal. Or build the project and execute the project with `./project generate`

## Testing the Data

To run the tests, make sure you first have data (if no data exists the program will error). Execute `./run_tests.sh` in the terminal to run the tests or build the project using the Makefile located in the build directory and run the `./project` file that gets generated.

After running the tests, all of the results will be organized into a output.csv file located in the local directory. If you rerun the test without deleting the old file, it will just overwrite it.