# CacheManager
A class that manages the cache.
The class saves the cache as a map:
- keys are the order in which a specific action was recently used.
- values are the output file and hash crc32 of the information in the input files.
Cash can hold a maximum number of values.


# AbstractOperation
Defines an abstract class of a specific action that confers polymorphism.
- members:
1. operation
2. input files for operation
3. output path
4. CacheManager object
- abstract methods:
1. function that return the hash of operation.
2. function that do the appopriate operation. 
3. function that check the given parameters of operation.


# MatrixOperation/ HashOperation/ ImageOperation
Classes that inherit from AbstractOperation and perform the abstract functions according to the specific operation.


