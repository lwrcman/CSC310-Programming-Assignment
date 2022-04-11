## * Function Declarations * ##

## Just a simple way to do a print
function PrintStatement() {
    echo ""
    echo $1
    echo ""
}

## Gets into the build directory to build the program, then 
## runs the program
PrintStatement "Building the project: "
cd build
make build

## Runs the project
PrintStatement "Running the generator found inside of the project: "
./project generate

## Cleans up after the run
PrintStatement "Cleaning up: "
make clean

## returns back to the directory state we are used to
cd ..