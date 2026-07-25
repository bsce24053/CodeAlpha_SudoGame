#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions.h"

TEST_CASE("Radix Sort - Random Numbers") {
    Sort sorter(5);
    
    sorter.addElement(170);
    sorter.addElement(45);
    sorter.addElement(75);
    sorter.addElement(90);
    sorter.addElement(802);

    sorter.radixSort();

    REQUIRE(sorter.getArray()[0] == 45);
    REQUIRE(sorter.getArray()[1] == 75);
    REQUIRE(sorter.getArray()[2] == 90);
    REQUIRE(sorter.getArray()[3] == 170);
    REQUIRE(sorter.getArray()[4] == 802);
}

TEST_CASE("Radix Sort - Already Sorted") {
    Sort sorter(5);

    sorter.addElement(1);
    sorter.addElement(2);
    sorter.addElement(3);
    sorter.addElement(4);
    sorter.addElement(5);

    sorter.radixSort();

    REQUIRE(sorter.getArray()[0] == 1);
    REQUIRE(sorter.getArray()[1] == 2);
    REQUIRE(sorter.getArray()[2] == 3);
    REQUIRE(sorter.getArray()[3] == 4);
    REQUIRE(sorter.getArray()[4] == 5);
}


TEST_CASE("Radix Sort - Single Element") {
    Sort sorter(1);

    sorter.addElement(42);

    sorter.radixSort();

    REQUIRE(sorter.getArray()[0] == 42);
}

TEST_CASE("Radix Sort - Empty Array") {
    Sort sorter(0); 

    sorter.radixSort();

    REQUIRE(sorter.getSize() == 0);
}

TEST_CASE("Count Sort - Random Numbers") {
    Sort sorter(5);

    sorter.addElement(4);
    sorter.addElement(2);
    sorter.addElement(2);
    sorter.addElement(8);
    sorter.addElement(3);

    sorter.countSort();

    REQUIRE(sorter.getArray()[0] == 2);
    REQUIRE(sorter.getArray()[1] == 2);
    REQUIRE(sorter.getArray()[2] == 3);
    REQUIRE(sorter.getArray()[3] == 4);
    REQUIRE(sorter.getArray()[4] == 8);
}

TEST_CASE("Count Sort - Already Sorted") {
    Sort sorter(5);

    sorter.addElement(1);
    sorter.addElement(2);
    sorter.addElement(3);
    sorter.addElement(4);
    sorter.addElement(5);

    sorter.countSort();

    REQUIRE(sorter.getArray()[0] == 1);
    REQUIRE(sorter.getArray()[1] == 2);
    REQUIRE(sorter.getArray()[2] == 3);
    REQUIRE(sorter.getArray()[3] == 4);
    REQUIRE(sorter.getArray()[4] == 5);
}


TEST_CASE("Count Sort - Single Element") {
    Sort sorter(1);

    sorter.addElement(42);

    sorter.countSort();

    REQUIRE(sorter.getArray()[0] == 42);
}

TEST_CASE("Count Sort - Empty Array") {
    Sort sorter(0); 

    sorter.countSort();

    REQUIRE(sorter.getSize() == 0);
}


TEST_CASE("Mix Sort") {
    Sort sorter(2);
    
    sorter.addElement(170);
    sorter.addElement(45);
    sorter.addElement(75);
    sorter.addElement(90);
    sorter.addElement(802);

    sorter.radixSort();
    
    sorter.addElement(17);
    sorter.addElement(3);
    sorter.addElement(45);
    sorter.addElement(789);
    sorter.addElement(912);

    REQUIRE(sorter.getArray()[0] == 3);
    REQUIRE(sorter.getArray()[1] == 17);
    REQUIRE(sorter.getArray()[2] == 45);
    REQUIRE(sorter.getArray()[3] == 45);
    REQUIRE(sorter.getArray()[4] == 75);
    REQUIRE(sorter.getArray()[5] == 90);
    REQUIRE(sorter.getArray()[6] == 170);
    REQUIRE(sorter.getArray()[7] == 789);
    REQUIRE(sorter.getArray()[8] == 802);
    REQUIRE(sorter.getArray()[9] == 912);
}


