# MasterPoker

Master Poker is a poker engine created to be open source and easy to use so that anyone can use it to make projects.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

To use with a project, add the library to your project as a reference (or manually if you want to use in different solution. )

Library supports being built as DLL and statically, but if building as DLL i would recomend commenting out MP_BUILD_STATIC in Master.h as having it uncommented
will allow some compile time optimizations to be made (enables declspec(dllexport)) on supported functions

### Prerequisites

To get this software working you require VS2017+. You can probably compile it for linux; nothing here is windows proprietary but I do not provide a makefile.

To get the test cases up and running you will also require boost and know how to get it working.


### Installing

How to run and test this software. 

clone the repository

```
git clone https://github.com/brodiequinlan/MasterPoker
```
Open the project in VS2017+. You are pretty much done (assuming boost is included in your projects by default). At this point, I do not make a *make* system, nor have I setup post-build steps properly and therefore
you will have to manually move the DLL produced by "MasterEngine" to the working directory of "Tests" or "Equity Calculator". I know, annoying. 


## Running the tests

Set the startup project to "Tests" and run. this will test the engine and make sure any changes have not broken functionality.



## Authors

* **Brodie Quinlan** - *All work* - [BrodieQuinlan](https://github.com/brodiequinlan)


## License

This project is licensed under the Apache License - see the [LICENSE](LICENSE) file for details

## Acknowledgments

** Code was not directly taken from https://github.com/TheCherno/Hazel but the way the project setup is inspired by it, therefore shoutout.