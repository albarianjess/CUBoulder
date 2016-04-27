#include <omp.h> //add multithreading for for-loop
#include <stdio.h>
#include "cs1300bmp.h"
#include <iostream>
#include <fstream>
#include "Filter.h"

using namespace std;

#include "rtdsc.h"

//
// Forward declare the functions
//
Filter * readFilter(string filename);
double applyFilter(Filter *filter, cs1300bmp *input, cs1300bmp *output);

int
main(int argc, char **argv)
{

  if ( argc < 2) {
    fprintf(stderr,"Usage: %s filter inputfile1 inputfile2 .... \n", argv[0]);
  }

  //
  // Convert to C++ strings to simplify manipulation
  //
  string filtername = argv[1];

  //
  // remove any ".filter" in the filtername
  //
  string filterOutputName = filtername;
  string::size_type loc = filterOutputName.find(".filter");
  if (loc != string::npos) {
    //
    // Remove the ".filter" name, which should occur on all the provided filters
    //
    filterOutputName = filtername.substr(0, loc);
  }

  Filter *filter = readFilter(filtername);

  double sum = 0.0;
  int samples = 0;

  for (int inNum = 2; inNum < argc; inNum++) {
    string inputFilename = argv[inNum];
    string outputFilename = "filtered-" + filterOutputName + "-" + inputFilename;
    struct cs1300bmp *input = new struct cs1300bmp;
    struct cs1300bmp *output = new struct cs1300bmp;
    int ok = cs1300bmp_readfile( (char *) inputFilename.c_str(), input);

    if ( ok ) {
      double sample = applyFilter(filter, input, output);
      sum += sample;
      samples++;
      cs1300bmp_writefile((char *) outputFilename.c_str(), output);
    }
  }
  fprintf(stdout, "Average cycles per sample is %f\n", sum / samples);

}

struct Filter *
readFilter(string filename)
{
  ifstream input(filename.c_str());

  if ( ! input.bad() ) {
    int size = 0;
    input >> size;
    Filter *filter = new Filter(size);
    int div;
    input >> div;
    filter -> setDivisor(div);
    for (int i=0; i < size; i++) {
      for (int j=0; j < size; j++) {
	int value;
	input >> value;
	filter -> set(i,j,value);
      }
    }
    return filter;
  }
}


double
applyFilter(struct Filter *filter, cs1300bmp *input, cs1300bmp *output)
{

  long long cycStart, cycStop;

  cycStart = rdtscll(); //STARTS CYCLE TIMER

///////////////////////////////////////////
  output -> width = input -> width;
  output -> height = input -> height;
  int value = 0; //take out of loop

    int dim = filter -> getSize(); //replacing function call w/ constant
    int div = filter -> getDivisor(); //replacing function call w/ constant
    int* getptr = filter -> getData(); //accessing data directly instead of function call
    int inheight = input -> height - 1;
    int inwidth = input -> width - 1;
#pragma omp parallel for private(value)
//tells omp where to do the multithreading optimization
for(int col = 1; col < inheight; ++col) { //change to ++i, add inwidth, switch loop
for(int plane = 0; plane < 3; ++plane) { //change to ++i, switch for loop
for(int row = 1; row < inwidth ; ++row) { //change to ++i, add inheight    
  
  
    
          
        value = 0; //reset value to 0 each loop
     
      

	
	//for (int j = 0; j < dim; ++j) { //change to ++i //loop unrolling
	  
	//for (int i = 0; i < dim; ++i) { //change to ++i  

  value = value +  input -> color[col - 1][plane][row - 1] * getptr[0]; //changed get to getptr
  value = value +  input -> color[col][plane][row - 1] * getptr[1]; //changed get to getptr
  value = value +  input -> color[col + 1][plane][row - 1] * getptr[2]; //changed get to getptr

 value = value +  input -> color[col - 1][plane][row] * getptr[3]; //changed get to getptr
 value = value +  input -> color[col][plane][row] * getptr[4]; //changed get to getptr
 value = value +  input -> color[col + 1][plane][row] * getptr[5]; //changed get to getptr

 value = value +  input -> color[col - 1][plane][row + 1] * getptr[6]; //changed get to gtptr
 value = value +  input -> color[col][plane][row + 1] * getptr[7]; //changed get to getptr
 value = value +  input -> color[col + 1][plane][row + 1] * getptr[8]; //changed get to getptr
	//  }
	//}


	value = value / div;
	
        if ( value  < 0 ) { 
            value = 0;
        } else if ( value  > 255 ) { //added else if to check 1 instead of both
            value = 255;
        }
	output -> color[col][plane][row] = value;
      }
    }
  }
///////////////////////////////////////////

  cycStop = rdtscll(); // STOPS TIMER
  double diff = cycStop - cycStart;
  double diffPerPixel = diff / (output -> width * output -> height);
  fprintf(stderr, "Took %f cycles to process, or %f cycles per pixel\n",
	  diff, diff / (output -> width * output -> height));
  return diffPerPixel;
}
