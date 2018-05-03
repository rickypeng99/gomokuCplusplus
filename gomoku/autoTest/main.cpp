//
//  main.cpp
//  autoTest
//
//  Created by Ricky Peng on 4/30/18.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "helpers.hpp"



TEST_CASE( "test if is intersection", "[isIntersection]" ) {
 
    REQUIRE(isIntersection(51, 51));
}



