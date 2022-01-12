#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <pthread.h>
#include <math.h>

int raiseToPower(int num, int pow);

int *valueToBinary(int i, int rank);

int *elemsForN(int size);

int *binaryElements(int *arr, int size, int count);

int *massToBooleanFunc(int *arr, int *arr2, int size, int count, int t);

int *toANF(const int *func, int size);

int HammingWeight(const int *function, int size);

int funcIsBalanced(int weight, int pow);

int algebraicDeg(const int *func, int size, int count);

int HammingDistance(const int *func1, const int *func2, int size);

int funcsIsEqual(const int *func1, const int *func2, int size);

int NLinearity(int *func, int size, int count);

int *toPolarTable(const int *function, int size);

int myModulus(int number, int mod);

int *HadamardCoefficients(const int *func, int size, int count);

int HadamardMax(const int *arr, int size);

int HadamardNLinearity(int max, int count);

int *autoCorrelation(int *func, int size, int count);

int autoCorrelationMax(const int *arr, int size);

int expansionCriterion(const int *func, int size, int k);

int *WHT1PlusSet(const int *func, int size, int newSize, int max);

int *WHT1MinusSet(const int *func, int size, int newSize, int max);

int *WHT2PlusSet(const int *func, int size, int newSize, int max);

int *WHT2MinusSet(const int *func, int size, int newSize, int max);

int arrayUnion(const int a[], int n1, const int b[], int n2, int c[]);

int *linearFunctions(int size, int count, int t);

int *arrayAdd(const int *arr1, int size1, const int *arr2, int size2);

int *improvementSet(const int func[], const int *linearFunctions, int size, int linearMassSize, int WHTPlusSize);

int *HillClimbing(const int f[], const int *improvementSet, int size, int count);

int *roundableHillClimbing(const int f[], int size, int count);

int *SBoxToBooleanFunc(int *sbox, int size, int count);

int *booleanFunctionsToSBox(const int *arr, int size, int count);

int *propertiesOfBooleanFunc(int *arr, int size, int count);

int *linearCombinations(const int *arr, int size, int count);

int *propertiesOfLinearCombinations(const int *arr, int size, int count);

int *SBoxGenerating(int n, int m);

int *propertiesOfSBox(int *sbox, int size, int count);

int costFunction(int *sbox, int size, int count);

int NLOfSBox(const int *sbox, int size, int count);

int ACOfSBox(int *sbox, int size, int count);

int *simulatedAnnealing(const int *sbox, int size, int count);

int NLOfLinearCombinations(const int *arr, int size, int count);

int deltaUniformity(const int *arr, int size, int count);

int differenceTableMax(const int *sbox, int size);

int *binaryElementsApprox(int *arr, int size, int count);

int *SBoxApprox(int *sbox, int size, int count);

int approxTableMax(int *sbox, int size, int count);

int LATMax(int *sbox, int size, int count);

int cyclicStructure(const int *sbox, int size);

int fixedPoints(const int *sbox, int size);

int minDegCalculation(const int *arr, int size, int count);

int minDegree(int *sbox, int size, int count);

void buildOneRow(int *arr, int *monomials);

int numOfCombinations(int n, int d);

int rankCalculation(int rows, int cols, int a[rows][cols]);

int algebraicImmunity(const int *sbox, int size, int count);

void bubble_sort(int *data, int size);

int *WHTSpectrumForLinearComb(const int *arr, int size, int count);

int *ACForLinearComb(const int *arr, int size, int count);

int *DegForLinearComb(const int *arr, int size, int count);

int linearRedundancy(int *sbox, int size, int count, int sp [size-1][size], int ac [size-1][size]);

int *SBoxGeneratingDec(int n, int m, int counter);

int NLOfSBoxDec(int *sbox, int size, int count);

int *particleSwarmOptimization(int size, int count, int N, int maxIter, int mode, int *finalIter);

void FisherYates(int *arr, int n);

void bubblesortDescending(int *data, int size);

int myModulusDec(int number, int mod);

int *CombFromWHTMatrix(int *func, int size, int count);

int *CombFromWHTGoodComb(int *func, int size, int count);

void sortComb (int *s, int N);

int *sortAndFind(int *func, int size, int count);

long long costFunctionPicek(int *sbox, int size, int count);

long raiseToPowerLong(int num, int pow);

long long costFunctionCuba(int *sbox, int size, int count);

long long costFunctionWHS(int *sbox, int size, int count);

long long costFunctionCubaLinComb(int *sbox_d, int size, int count);

int aesSbox[] = {99, 124, 119, 123, 242, 107, 111, 197, 48, 1, 103, 43, 254, 215, 171, 118, 202, 130, 201, 125, 250,
                       89, 71, 240, 173, 212, 162, 175, 156, 164, 114, 192, 183, 253, 147, 38, 54, 63, 247, 204, 52, 165,
                       229, 241, 113, 216, 49, 21, 4, 199, 35, 195, 24, 150, 5, 154, 7, 18, 128, 226, 235, 39, 178, 117,
                       9, 131, 44, 26, 27, 110, 90, 160, 82, 59, 214, 179, 41, 227, 47, 132, 83, 209, 0, 237, 32, 252,
                       177, 91, 106, 203, 190, 57, 74, 76, 88, 207, 208, 239, 170, 251, 67, 77, 51, 133, 69, 249, 2, 127,
                       80, 60, 159, 168, 81, 163, 64, 143, 146, 157, 56, 245, 188, 182, 218, 33, 16, 255, 243, 210, 205,
                       12, 19, 236, 95, 151, 68, 23, 196, 167, 126, 61, 100, 93, 25, 115, 96, 129, 79, 220, 34, 42, 144,
                       136, 70, 238, 184, 20, 222, 94, 11, 219, 224, 50, 58, 10, 73, 6, 36, 92, 194, 211, 172, 98, 145,
                       149, 228, 121, 231, 200, 55, 109, 141, 213, 78, 169, 108, 86, 244, 234, 101, 122, 174, 8, 186, 120,
                       37, 46, 28, 166, 180, 198, 232, 221, 116, 31, 75, 189, 139, 138, 112, 62, 181, 102, 72, 3, 246, 14,
                       97, 53, 87, 185, 134, 193, 29, 158, 225, 248, 152, 17, 105, 217, 142, 148, 155, 30, 135, 233, 206,
                       85, 40, 223, 140, 161, 137, 13, 191, 230, 66, 104, 65, 153, 45, 15, 176, 84, 187, 22};

int main(int args, char **argv) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n = 8;
    int size = raiseToPower(2, n);

    int arr110NL[] = {99, 124, 119, 123, 242, 107, 111, 197, 48, 1, 103, 43, 254, 215, 171, 118, 202, 130, 201, 125, 250, 89, 71, 240, 173, 212, 162, 175, 156, 164, 114, 192, 183, 253, 147, 38, 54, 63, 204, 247, 52, 165, 229, 241, 113, 216, 49, 21, 4, 199, 35, 195, 24, 150, 5, 154, 7, 18, 128, 226, 235, 39, 178, 117, 9, 131, 44, 26, 27, 110, 90, 160, 82, 59, 214, 179, 41, 227, 47, 132, 83, 209, 0, 237, 32, 252, 177, 91, 106, 203, 190, 57, 74, 76, 88, 207, 208, 239, 170, 251, 67, 77, 51, 133, 69, 249, 2, 127, 80, 60, 159, 168, 81, 163, 64, 143, 146, 157, 56, 245, 188, 182, 218, 33, 16, 255, 243, 210, 205, 12, 19, 236, 95, 151, 68, 23, 196, 167, 126, 61, 100, 93, 25, 115, 96, 129, 79, 220, 34, 42, 144, 136, 70, 238, 184, 20, 222, 94, 11, 219, 224, 50, 58, 10, 73, 6, 36, 92, 194, 211, 172, 98, 145, 149, 228, 121, 231, 200, 55, 109, 141, 213, 78, 169, 108, 86, 244, 234, 101, 122, 174, 8, 186, 120, 37, 46, 28, 166, 180, 198, 232, 221, 116, 31, 75, 189, 139, 138, 112, 62, 181, 102, 72, 3, 246, 14, 97, 53, 87, 185, 134, 193, 29, 158, 225, 248, 152, 17, 105, 217, 142, 148, 155, 30, 135, 233, 206, 85, 40, 223, 140, 161, 137, 13, 191, 230, 66, 104, 65, 153, 45, 15, 176, 84, 187, 22};

    int arr108NL[] = {99, 124, 119, 123, 242, 107, 111, 197, 48, 1, 103, 43, 254, 215, 171, 118, 202, 130, 201, 125, 250, 89, 71, 240, 173, 212, 162, 175, 156, 164, 114, 192, 183, 253, 147, 38, 54, 63, 230, 251, 52, 165, 229, 241, 113, 216, 49, 21, 4, 199, 35, 195, 24, 150, 5, 154, 7, 18, 128, 226, 235, 39, 178, 117, 9, 131, 44, 26, 27, 110, 90, 160, 82, 59, 214, 179, 41, 227, 47, 132, 83, 209, 0, 237, 32, 252, 177, 91, 106, 203, 190, 57, 74, 76, 88, 207, 208, 239, 170, 206, 67, 77, 51, 133, 69, 249, 2, 127, 80, 60, 159, 168, 81, 163, 64, 143, 146, 157, 56, 245, 188, 182, 218, 33, 16, 255, 243, 210, 205, 12, 19, 236, 95, 151, 68, 23, 196, 167, 126, 61, 100, 93, 25, 115, 96, 129, 79, 220, 34, 42, 144, 136, 70, 238, 184, 20, 222, 94, 11, 219, 224, 50, 58, 10, 73, 6, 36, 92, 194, 211, 172, 98, 145, 149, 228, 121, 231, 200, 55, 109, 141, 213, 78, 169, 108, 86, 244, 234, 101, 122, 174, 8, 186, 120, 37, 46, 28, 166, 180, 198, 232, 221, 116, 31, 75, 189, 139, 138, 112, 62, 181, 102, 72, 3, 246, 14, 97, 53, 87, 185, 134, 193, 29, 158, 225, 248, 152, 17, 105, 217, 142, 148, 155, 30, 135, 233, 153, 85, 40, 223, 140, 161, 137, 13, 191, 204, 66, 104, 65, 176, 45, 15, 84, 187, 247, 22};

    int arr106NL[] = {99, 124, 119, 123, 242, 107, 111, 197, 48, 5, 103, 43, 254, 215, 171, 118, 202, 130, 201, 125, 250, 89, 71, 240, 173, 212, 162, 175, 156, 164, 114, 192, 183, 253, 147, 38, 54, 63, 247, 204, 52, 165, 229, 241, 113, 216, 49, 21, 0, 199, 35, 195, 24, 150, 4, 154, 7, 18, 128, 226, 235, 39, 178, 117, 9, 131, 44, 26, 27, 110, 90, 160, 82, 59, 214, 179, 41, 227, 47, 132, 83, 209, 1, 237, 32, 252, 177, 91, 106, 203, 190, 57, 74, 76, 88, 207, 208, 239, 170, 251, 67, 77, 51, 133, 69, 249, 3, 127, 80, 60, 159, 168, 81, 163, 64, 143, 146, 157, 56, 245, 188, 182, 218, 33, 16, 255, 243, 210, 205, 12, 19, 236, 95, 151, 68, 23, 196, 167, 126, 61, 100, 93, 25, 115, 96, 129, 79, 220, 34, 42, 144, 136, 70, 238, 184, 20, 222, 94, 11, 219, 224, 50, 58, 10, 73, 6, 36, 92, 194, 211, 172, 98, 145, 149, 228, 121, 231, 200, 55, 109, 141, 213, 78, 169, 108, 86, 244, 234, 101, 122, 174, 8, 186, 120, 37, 46, 28, 166, 180, 198, 232, 221, 116, 31, 75, 189, 139, 138, 112, 62, 181, 102, 72, 2, 246, 14, 97, 53, 87, 185, 134, 193, 29, 158, 225, 248, 152, 17, 105, 217, 142, 148, 155, 30, 135, 233, 206, 85, 40, 223, 140, 161, 137, 13, 191, 230, 66, 104, 65, 153, 45, 15, 176, 84, 187, 22};

    int arr104NL[] = {111, 124, 119, 123, 42, 107, 36, 197, 48, 121, 195, 43, 254, 1, 77, 118, 202, 130, 201, 89, 250, 125, 71, 240, 173, 212, 162, 175, 156, 164, 102, 192, 183, 253, 147, 38, 54, 63, 154, 151, 52, 165, 229, 241, 113, 216, 217, 21, 66, 199, 35, 40, 24, 150, 5, 141, 7, 18, 128, 226, 235, 39, 178, 117, 9, 131, 44, 26, 27, 110, 90, 160, 82, 59, 214, 179, 41, 227, 47, 132, 83, 209, 0, 237, 32, 252, 177, 91, 106, 203, 190, 57, 74, 76, 88, 207, 208, 239, 170, 251, 67, 171, 51, 133, 69, 249, 2, 127, 80, 60, 159, 168, 81, 163, 64, 143, 146, 157, 56, 245, 188, 182, 218, 33, 16, 255, 243, 210, 205, 12, 19, 236, 95, 101, 68, 23, 196, 167, 126, 61, 100, 93, 25, 115, 96, 129, 79, 220, 34, 242, 144, 136, 70, 238, 184, 20, 222, 94, 11, 219, 224, 50, 58, 10, 73, 6, 99, 92, 194, 211, 172, 98, 145, 149, 228, 215, 231, 200, 55, 109, 84, 213, 78, 169, 108, 86, 244, 234, 37, 122, 174, 8, 186, 120, 97, 46, 28, 166, 180, 198, 232, 221, 116, 31, 75, 189, 139, 138, 112, 62, 181, 114, 72, 3, 246, 14, 103, 53, 87, 185, 134, 193, 29, 158, 225, 248, 152, 17, 105, 49, 142, 148, 155, 30, 135, 233, 206, 85, 247, 223, 140, 161, 137, 13, 191, 230, 4, 104, 65, 153, 45, 15, 176, 22, 187, 204};

    int arr102NL[] = {99, 124, 119, 123, 242, 107, 111, 202, 80, 1, 103, 43, 254, 215, 171, 118, 197, 235, 201, 92, 250, 89, 71, 240, 173, 212, 224, 175, 156, 164, 114, 192, 183, 253, 48, 38, 54, 222, 63, 19, 52, 165, 229, 241, 113, 216, 49, 142, 145, 199, 35, 195, 24, 150, 5, 154, 7, 18, 128, 226, 130, 39, 178, 117, 9, 131, 44, 26, 27, 110, 90, 160, 82, 59, 214, 179, 41, 227, 47, 132, 83, 209, 0, 237, 32, 252, 177, 91, 106, 203, 190, 57, 74, 76, 88, 207, 208, 239, 170, 251, 67, 77, 51, 133, 69, 249, 28, 127, 147, 60, 159, 168, 81, 163, 64, 143, 146, 157, 56, 245, 188, 182, 218, 33, 16, 255, 243, 210, 205, 12, 2, 236, 95, 151, 68, 23, 196, 167, 126, 61, 100, 93, 25, 115, 96, 129, 79, 220, 34, 42, 144, 136, 70, 238, 184, 20, 15, 94, 11, 219, 187, 50, 58, 10, 73, 6, 36, 125, 194, 211, 172, 98, 4, 149, 228, 121, 231, 200, 55, 109, 141, 213, 78, 169, 108, 86, 244, 234, 101, 122, 174, 8, 186, 120, 37, 46, 66, 166, 180, 198, 232, 221, 116, 31, 75, 189, 139, 138, 112, 62, 181, 102, 72, 3, 246, 14, 97, 53, 87, 185, 134, 193, 29, 158, 225, 248, 152, 17, 105, 217, 21, 148, 155, 30, 135, 233, 206, 85, 40, 223, 140, 161, 137, 13, 191, 230, 153, 104, 65, 204, 45, 162, 176, 84, 22, 247};

    int arr100NL[] = {99, 124, 119, 123, 242, 107, 57, 201, 130, 1, 103, 43, 254, 72, 171, 112, 202, 48, 129, 125, 250, 89, 71, 240, 173, 212, 162, 21, 156, 44, 114, 192, 105, 253, 147, 38, 54, 31, 138, 237, 52, 187, 229, 249, 113, 216, 217, 175, 4, 199, 35, 195, 24, 150, 5, 154, 7, 18, 128, 226, 235, 39, 178, 117, 9, 131, 164, 26, 27, 110, 90, 160, 82, 59, 214, 179, 41, 227, 47, 132, 83, 209, 0, 142, 32, 252, 177, 91, 165, 203, 190, 111, 74, 76, 88, 207, 208, 239, 170, 251, 67, 77, 51, 133, 69, 241, 2, 127, 80, 60, 159, 168, 81, 163, 64, 143, 146, 157, 56, 245, 188, 182, 218, 33, 16, 255, 243, 210, 205, 12, 19, 236, 95, 151, 68, 23, 196, 167, 126, 61, 100, 93, 25, 115, 96, 197, 79, 220, 34, 42, 144, 136, 70, 238, 184, 20, 222, 94, 11, 219, 224, 50, 58, 10, 73, 6, 36, 92, 194, 211, 172, 98, 145, 149, 228, 121, 231, 200, 55, 109, 141, 213, 78, 169, 108, 86, 244, 234, 101, 122, 174, 8, 186, 120, 37, 46, 28, 166, 180, 198, 232, 221, 116, 63, 75, 189, 139, 30, 118, 62, 181, 102, 215, 3, 246, 14, 97, 53, 87, 185, 134, 193, 29, 158, 225, 248, 152, 17, 183, 49, 140, 148, 155, 230, 135, 233, 206, 85, 40, 223, 84, 161, 137, 13, 191, 176, 66, 104, 65, 153, 45, 15, 22, 247, 106, 204};

    int arr98NL[] = {239, 165, 56, 107, 229, 59, 66, 143, 81, 166, 241, 161, 140, 97, 36, 183, 153, 240, 225, 220, 87, 203, 139, 43, 54, 32, 253, 124, 73, 119, 171, 93, 212, 168, 83, 238, 222, 127, 60, 223, 207, 77, 174, 248, 19, 245, 12, 147, 106, 167, 164, 205, 187, 86, 69, 219, 128, 65, 1, 74, 75, 180, 172, 13, 188, 71, 197, 226, 150, 201, 3, 76, 244, 52, 155, 88, 39, 191, 125, 148, 228, 154, 170, 61, 53, 137, 158, 37, 9, 21, 94, 221, 123, 185, 218, 22, 92, 28, 210, 68, 217, 251, 50, 199, 101, 64, 115, 55, 252, 255, 200, 178, 176, 79, 169, 152, 67, 78, 216, 49, 129, 51, 177, 30, 105, 29, 85, 18, 202, 23, 63, 190, 195, 108, 198, 62, 136, 27, 130, 254, 109, 141, 116, 189, 26, 91, 102, 213, 111, 237, 120, 84, 231, 232, 90, 193, 151, 159, 4, 10, 38, 100, 48, 33, 132, 184, 214, 99, 34, 57, 234, 17, 156, 250, 98, 204, 15, 80, 126, 41, 181, 209, 45, 162, 95, 227, 131, 233, 8, 134, 243, 236, 122, 149, 104, 242, 194, 5, 0, 247, 89, 145, 114, 40, 24, 35, 175, 246, 249, 103, 72, 112, 135, 96, 117, 215, 6, 206, 42, 230, 47, 173, 44, 46, 118, 31, 7, 113, 163, 192, 82, 235, 208, 70, 133, 58, 160, 2, 11, 186, 14, 179, 142, 211, 144, 182, 16, 196, 138, 157, 224, 121, 110, 20, 25, 146};

    int arr96NL[] = {139, 96, 129, 113, 56, 159, 141, 251, 242, 187, 24, 7, 21, 28, 238, 161, 226, 127, 39, 125, 106, 208, 0, 233, 136, 58, 177, 235, 119, 220, 77, 172, 207, 30, 97, 214, 41, 31, 99, 245, 231, 137, 73, 5, 164, 12, 246, 143, 166, 43, 197, 19, 254, 140, 157, 118, 170, 248, 179, 50, 75, 203, 237, 2, 149, 174, 232, 225, 255, 201, 114, 210, 63, 55, 17, 117, 217, 10, 247, 218, 145, 204, 249, 121, 253, 88, 224, 81, 38, 183, 9, 27, 193, 101, 42, 54, 48, 60, 45, 152, 18, 83, 4, 150, 22, 111, 46, 189, 213, 85, 105, 34, 25, 202, 250, 209, 108, 47, 184, 66, 72, 178, 74, 227, 51, 36, 107, 78, 40, 182, 241, 15, 133, 173, 82, 243, 234, 142, 168, 191, 103, 52, 6, 69, 158, 37, 91, 53, 35, 11, 123, 194, 240, 13, 154, 169, 180, 192, 196, 230, 61, 68, 236, 219, 1, 212, 57, 134, 162, 175, 23, 211, 33, 76, 116, 104, 167, 131, 26, 16, 138, 120, 165, 90, 190, 70, 64, 67, 79, 59, 215, 181, 223, 126, 244, 229, 200, 151, 109, 205, 171, 155, 62, 186, 8, 146, 65, 98, 110, 86, 14, 112, 95, 228, 222, 135, 252, 49, 188, 94, 176, 156, 128, 147, 3, 132, 102, 185, 239, 87, 144, 124, 148, 199, 206, 84, 32, 80, 100, 29, 44, 20, 160, 115, 71, 198, 92, 93, 89, 216, 163, 153, 221, 122, 130, 195};

    /*long long cost = costFunctionPicek(ar7,size,n);
    printf("\ncost by Picek = %lld", cost);

    long long costCuba = costFunctionCuba(ar7,size,n);
    printf("\ncost by Cuba = %lld", costCuba);*/

    long long costCuba = costFunctionCubaLinComb(arr96NL,size,n);
    printf("\ncost by CUBA = %lld", costCuba);

    return 0;
}

//Функція приведення числа за модулем дуякого числа

int myModulus(int number, int mod) {
    if (number < 0) {
        while (number < 0) {
            number = number + mod;
        }
    }
    return number % 2;
}

//Функція приведення числа за модулем дуякого числа

int myModulusDec(int number, int mod) {
    if (number < 0) {
        while (number < 0) {
            number = number + mod;
        }
    }
    return number % mod;
}

//Функція перетворення елементів з десяткової СЧ у двійкову СЧ, для певного ступеня N

int *binaryElements(int *arr, int size, int count) {
    int *result = calloc(size * count, sizeof(int));
    for (int i = 0; i < size; ++i) {
        int *bin = valueToBinary(arr[i], count);
        for (int j = 0, k = count - 1; j < count; ++j, k--) {
            result[j * size + i] = bin[k];
        }
        free(bin);
    }
    return result;
}

//Функція перетворення масиву чисел у двійковій системі до таблиці істиності

int *massToBooleanFunc(int *arr, int *arr2, int size, int count, int t) {
    int calc;
    int calc2 = 1;
    //printf("\n");
    //printf("t = %d", t);
    //printf("\n");
    int *calculation = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        int *bin = valueToBinary(arr[i], count);
        for (int j = 0, k = count - 1; j < count; ++j, k--) {
            //printf("\n");
            //printf("bin k = %d", bin[k]);
            //printf("\n");
            //printf("arr2 i = %d", arr2[j*size+t]);
            calc = raiseToPower(arr2[j * size + t], bin[k]);
            //printf("\n");
            //printf("raised to power = %d", calc);
            //printf("%d\n",bin[j]);
            calc2 = calc2 * calc;
            //printf("\n");
            //printf("calc2 = %d", calc2);
            calculation[arr[i]] = calc2;
        }
        calc2 = 1;
        /*for (int r = 0; r<size; ++r){
            if(arr3[r]!=0){
                printf(" rrr %d", calculation[r]);
                calc3 = calc3^calculation[r];
                printf("\n");
                printf("calc3 = %d", calc3);
            }
        }*/
        //printf("\n");
        //printf("calc3 = %d", calc3);
        //printf("\n");
    }
    return calculation;
}

//Функція перетворення числа з десяткової СЧ у двійкову СЧ

int *valueToBinary(int i, int rank) {
    int *res = calloc(rank, sizeof(int));
    for (int j = 0; j < rank; ++j) {
        res[rank - 1 - j] = i >> j & 1;
    }
    return res;
}

//Функція зведення до ступеня

int raiseToPower(int num, int pow) {
    int res = 1;
    for (int i = 0; i < pow; ++i) {
        res *= num;
    }
    return res;
}

//Функція зведення до ступеня long

long raiseToPowerLong(int num, int pow) {
    long res = 1;
    for (int i = 0; i < pow; ++i) {
        res *= num;
    }
    return res;
}

//Функція генерації чисел для вхідних векторів ступеня N

int *elemsForN(int size) {
    int *result = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        result[i] = i;
    }
    return result;
}

//Функція переведення з таблиці істиності до АНФ

int *toANF(const int *func, int size) {
    int *matrix = calloc(size * size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        matrix[i] = func[size - 1 - i];
    }
    /*for (int k = 0; k < size; ++k) {
        for (int l = 0; l < size; ++l) {
            printf(" %d", matrix[k*size+l]);
        }
        printf("\n");
    }*/
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < size - i; ++j) {
            matrix[i * size + j] = (matrix[size * (i - 1) + j] + matrix[size * (i - 1) + (j + 1)]) % 2;
            //printf(" %d", matrix[i * size + j]);
        }
        //printf("\n");
    }
    int *coefficients = calloc(size,sizeof(int));
    for (int i = 0; i < size; ++i) {
        coefficients[i] = matrix[i * size];
    }
    free(matrix);
    return coefficients;
}

//Функція обчислення ваги Хеммінга

int HammingWeight(const int *function, int size) {
    int weight = 0;
    for (int i = 0; i < size; ++i) {
        if (function[i]) {
            weight++;
        }
    }
    return weight;
}

//Функція визначення збалансованості функції

int funcIsBalanced(int weight, int pow) {
    int flag = 1;
    if (weight == raiseToPower(2, pow - 1)) {
        //printf("\nFunction is BALANCED!");
        return flag;
    } else {
        //printf("\nFunction is NOT BALANCED!");
        flag = 0;
        return flag;
    }
}

//Функція визначення алгебраїчного ступеня функції

int algebraicDeg(const int *func, int size, int count) {
    int *ar = toANF(func,size);
    int result;
    int flag = 0;
    int k = 0;
    int highestDec;
    int newSize = 0;
    /*for (int i = 0; i < size; ++i){
        printf("%d, ",ar[i]);
    }*/
    for (int i = 0; i < size; ++i) {
        if (ar[i]) {
            newSize++;
        }
    }
    //printf("\n newSize  = %d",newSize);
    int *deg = calloc(newSize, sizeof(int));
    for (int i = 0; i < size; ++i) {
        if (ar[i]) {
            //printf("\ni = %d",i);
            int *bin = valueToBinary(i, count);
            for (int j = 0; j < count; ++j) {
                if (bin[j] == 1) {
                    ++flag;
                }
            }
            deg[k] = flag;
            //printf("\n deg k  = %d",deg[k]);
            flag = 0;
            ++k;
            free(bin);
        }
    }
    highestDec = deg[0];
    for (int l = 0; l < newSize; ++l) {
        if (deg[l] > highestDec) {
            highestDec = deg[l];
        }
    }
    //printf("\nH deg   = %d",highestDec);
    result = highestDec;
    free(ar);
    free(deg);
    return result;
}

//Функція визначення відстані Хемінга

int HammingDistance(const int *func1, const int *func2, int size) {
    int res = 0;
    for (int i = 0; i < size; ++i) {
        if ((func1[i] ^ func2[i]) != 0) res++;
    }
    return res;
}

//Функція визначення рівності між функціями

int funcsIsEqual(const int *func1, const int *func2, int size) {
    int flag = 0;
    for (int i = 0; i < size; ++i) {
        if (func1[i] == func2[i]) {
            flag++;
        }
    }
    return flag == size;
}

//Функція визначення нелінійності функції

int NLinearity(int *func, int size, int count) {
    int minimumNL;
    int minimumNL1;
    int minimumNL2;
    int matrixColumns = size;
    int matrixRows = raiseToPower(2, matrixColumns);
    int *functions = calloc(matrixRows * matrixColumns, sizeof(int));
    int *functions2 = elemsForN(matrixRows);
    int *testfunc = calloc(size, sizeof(int));
    /*for (int i = 0; i < matrixRows; ++i) {
        printf(" %d",functions2 [i]);
    }*/
    //printf("\n");
    for (int i = 0; i < matrixRows; ++i) {
        int *bin = valueToBinary(functions2[i], matrixColumns);
        for (int j = 0; j < matrixColumns; ++j) {
            //printf(" bin j = %d", bin[j]);
            //*(functions + i * cols + j) = (i >> cols - j - 1) & 1u;
            functions[i * matrixColumns + j] = bin[j];
            //printf(" %d",functions [i * matrixColumns + j]);
        }
        //printf("\n");
        free(bin);
    }
    //minimumNL = HammingDistance(func, functions, size);
    minimumNL1 = HammingDistance(func, functions, size);
    int *bin = valueToBinary(matrixRows - 1, matrixColumns);
    for (int j = 0; j < matrixColumns; ++j) {
        testfunc[j] = bin[j];
    }
    /*for (int i = 0; i < size; ++i) {
        printf(" %d",testfunc[i]);
    }*/
    //printf(" %d",minimumNL1);
    minimumNL2 = HammingDistance(func, testfunc, size);
    minimumNL = minimumNL1;
    if (minimumNL2 < minimumNL1) {
        minimumNL = minimumNL2;
    }
    for (int i = 0; i < matrixRows; ++i) {
        if (algebraicDeg(functions + matrixColumns * i, size, count) <= 1 &&
            !funcsIsEqual(func, functions + matrixColumns * i, size)) {
            int newMinHD = HammingDistance(func, functions + matrixColumns * i, matrixColumns);
            //printf(" NEW MID HD%d",newMinHD);
            if (newMinHD < minimumNL) {
                minimumNL = newMinHD;
            }
        }
    }
    int result = minimumNL;
    free(functions);
    free(functions2);
    free(testfunc);
    free(bin);
    return result;
}

//Функція представлення таблиці істиності в полярному вигляді

int *toPolarTable(const int *function, int size) {
    int *res = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        res[i] = raiseToPower(-1, function[i]);
    }
    return res;
}

//Функція визначення коефіцієнтів перетворення Уолдша-Адамара

int *HadamardCoefficients(const int *func, int size, int count) {
    int *result = calloc(size, sizeof(int));
    int *test = calloc(size * count, sizeof(int));
    int *functions2 = elemsForN(size);
    /*for (int i = 0; i < size; ++i) {
        printf(" %d",functions2 [i]);
    }*/
    //printf("\n");
    for (int i = 0; i < size; ++i) {
        int *bin = valueToBinary(functions2[i], count);
        for (int j = 0; j < count; ++j) {
            //printf(" bin j = %d", bin[j]);
            //*(functions + i * cols + j) = (i >> cols - j - 1) & 1u;
            test[i * count + j] = bin[j];
            //printf(" %d",test [i * count + j]);
        }
        //printf("\n");
        free(bin);
    }
    int *w = calloc(count, sizeof(int));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < count; ++j) {
            w[j] = test[i * count + j];
            //printf("w = %d", w[j]);
        }
        int res = 0;
        for (int j = 0; j < size; ++j) {
            int r = 0;
            for (int k = 0; k < count; ++k) {
                r += myModulus(w[k] * test[j * count + k], 2);
            }
            res += raiseToPower(-1, myModulus(func[j] + r, 2));
        }
        result[i] = res;
    }
    free(test);
    free(functions2);
    free(w);
    return result;
}

//Функція визначення найбільшого коефіцієнта перетворення Уолдша-Адамара

int HadamardMax(const int *arr, int size) {
    int maxCoefficient = abs(arr[0]);
    for (int i = 0; i < size; ++i) {
        if (abs(arr[i]) > abs(maxCoefficient)) {
            maxCoefficient = abs(arr[i]);
        }
    }
    //printf("max coef %d", maxCoefficient);
    return maxCoefficient;
}

//Функція визначення нелінійності функції через коефіцієнти Уолдша-Адамара

int HadamardNLinearity(int max, int count) {
    int nl = (raiseToPower(2, count) - max) / 2;
    return nl;
}

//Функція обчислення автокореляційної функції

int *autoCorrelation(int *func, int size, int count) {
    int temp = 0;
    int *acFunc = calloc(size, sizeof(int));
    int *polFunc = toPolarTable(func, size);
    int *polFunc2 = calloc(size, sizeof(int));
    for (int i =0, k = size-1; i<size, k>=0; ++i, k--) {
        polFunc2[i] = polFunc[k];
        //printf("\npf2= %d", polFunc2[i]);
    }
    acFunc[0] = raiseToPower(2, count);
    for (int f = 1; f < size; ++f) {
        for (int j = 0; j < size; ++j) {
            temp = polFunc2[j] * polFunc2[j ^ f];
            //printf("\nj = %d", j);
            //printf("\nj^i = %d", j^i);
            //printf("\ntemp= %d", temp);
            acFunc[f] = acFunc[f] + temp;
        }
        //printf("ac i = %d", acFunc[i]);
    }
    free(polFunc);
    free(polFunc2);
    return acFunc;
}

//Функція обчислення автокореляції з функції автокореляції

int autoCorrelationMax(const int *arr, int size) {
    int maxCoefficient = abs(arr[1]);
    for (int i = 1; i < size; ++i) {
        if (abs(arr[i]) > maxCoefficient) {
            //printf("%d", arr[i]);
            maxCoefficient = abs(arr[i]);
        }
    }
    return maxCoefficient;
}

//Функція визначення відповідності критеріям

int expansionCriterion(const int *func, int size, int k) {
    int result = 0;
    for (int i = 0; i < size; ++i) {
        result += func[i] ^ func[i ^ k];
    }
    if (result == size / 2) {
        printf("\nComply with Criterion KP(%d)", k);
    } else {
        printf("\nNot comply with Criterion KP(%d)", k);
    }
    return result;
}

//Функція визначення множини W1+

int *WHT1PlusSet(const int *func, int size, int newSize, int max) {
    if (newSize != 0) {
        int *result = calloc(newSize, sizeof(int));
        int k = 0;
        for (int j = 0; j < size; ++j) {
            if (func[j] == max) {
                result[k] = j;
                k++;
            }
        }
        return result;
    } else {
        return NULL;
    }
}

//Функція визначення множини W1-

int *WHT1MinusSet(const int *func, int size, int newSize, int max) {
    if (newSize != 0) {
        int *result = calloc(newSize, sizeof(int));
        int k = 0;
        for (int j = 0; j < size; ++j) {
            if (func[j] == -max) {
                result[k] = j;
                k++;
            }
        }
        return result;
    } else {
        return NULL;
    }
}

//Функція визначення множини W2+

int *WHT2PlusSet(const int *func, int size, int newSize, int max) {
    if (newSize != 0) {
        int *result = calloc(newSize, sizeof(int));
        int k = 0;
        for (int j = 0; j < size; ++j) {
            if (func[j] == (max - 2)) {
                result[k] = j;
                k++;
            }
        }
        return result;
    } else {
        return NULL;
    }
}

//Функція визначення множини W2-

int *WHT2MinusSet(const int *func, int size, int newSize, int max) {
    if (newSize != 0) {
        int *result = calloc(newSize, sizeof(int));
        int k = 0;
        for (int j = 0; j < size; ++j) {
            if (func[j] == -(max - 2)) {
                result[k] = j;
                k++;
            }
        }
        return result;
    } else {
        return NULL;
    }
}

//Функція виконання операції "об'єднання" над масивами

int arrayUnion(const int a[], int n1, const int b[], int n2, int c[]) {
    int n = 0, i = 0, j = 0;

    while ((i < n1) && (j < n2)) {
        if (a[i] < b[j])
            c[n++] = a[i++];
        else if (a[i] > b[j])
            c[n++] = b[j++];
        else {
            c[n++] = a[i++];
            ++j;
        }
    }

    while (i < n1)
        c[n++] = a[i++];
    while (j < n2)
        c[n++] = b[j++];
    return n;
}

//Функція обчислення лінійної функції для заданого омега

int *linearFunctions(int size, int count, int t) {
    int calc1 = 0;
    int calc2 = 0;
    int sum = 0;
    int *binElems = elemsForN(size);
    int *ar = binaryElements(binElems, size, count);
    int *bin = valueToBinary(t, count);
    /*for (int i = 0; i < count; ++i) {
        printf("%d ", bin[i]);
    }*/
    //printf("\n");
    int *result = calloc(size, sizeof(int));
    for (int j = 0; j < size; ++j) {
        for (int i = 0, k = count - 1; i < count, k >= 0; ++i, --k) {
            calc1 = ar[i * size + j] * bin[k];
            //printf("%d ", bin[k]);
            //printf("%d ", calc1);
            sum = sum ^ calc1;
            //printf("%d ", sum);
        }
        //printf("%d ", sum);
        result[j] = sum;
        sum = 0;
        //printf("\n");
    }
    free(binElems);
    free(bin);
    free(ar);
    return result;
}

//Функція з'єднання двох масивів

int *arrayAdd(const int *arr1, int size1, const int *arr2, int size2) {
    int linearMassSize = size1 + size2;
    int *result = calloc(linearMassSize, sizeof(int));
    for (int i = 0; i < size1; ++i) {
        result[i] = arr1[i];
    }
    if (size2 != 0) {
        for (int j = 0; j < size2; ++j) {
            result[j + size1] = arr2[j];
        }
    }
    return result;
}

//Функція знаходження набору покращень

int *improvementSet(const int func[], const int *linearFunctions, int size, int linearMassSize, int WHTPlusSize) {
    int counter = 0;
    int k = 0;
    int flag = 1;
    int *result = calloc(size, sizeof(int));
    int *result1 = calloc(size, sizeof(int));
    int *result2 = calloc(size, sizeof(int));
    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < WHTPlusSize; ++i) {
            if ((func[j] == linearFunctions[i * size + j])) {
                flag = 1;
            } else {
                flag = 0;
                break;
            }
        }
        //printf("flag %d ", flag);
        if (flag == 1) {
            result1[j] = 1;
        } else {
            result1[j] = 0;
        }

    }
    /*for (int j = 0; j < size; ++j) {
        printf("%d ", result1[j]);
    }*/
    if (WHTPlusSize < linearMassSize) {
        for (int j = 0; j < size; ++j) {
            for (int i = WHTPlusSize; i < linearMassSize; ++i) {
                if ((func[j] != linearFunctions[i * size + j])) {
                    flag = 1;
                } else {
                    flag = 0;
                    break;
                }
            }
            //printf("flag %d ", flag);
            if (flag == 1) {
                result2[j] = 1;
            } else {
                result2[j] = 0;
            }

        }
        /*for (int j = 0; j < size; ++j) {
            printf("%d ", result2[j]);
        }*/
        for (int j = 0; j < size; ++j) {
            if ((result1[j] == 1) && (result2[j] == 1) && (result1[j] == result2[j])) {
                result[j] = 1;
            } else {
                result[j] = 0;
            }
        }
    } else {
        for (int j = 0; j < size; ++j) {
            result[j] = result1[j];
        }
    }
    for (int j = 0; j < size; ++j) {
        if (result[j] == 1) {
            counter++;
        }
    }
    if (counter == 0) {
        printf("\nIMPROVEMENT IS UNAVAILABLE");
    }

    free(result1);
    free(result2);
    return result;
}

//Функція підвищення нелінійності методом Градієнтного Підйому

int *HillClimbing(const int f[], const int *improvementSet, int size, int count) {
    int *ftemp = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ftemp[j] = f[j];
        }
        if (improvementSet[i] == 1) {
            if (ftemp[i] == 0) {
                ftemp[i] = 1;
            } else {
                ftemp[i] = 0;
            }
            printf("\n|---------------------------------|");
            printf("\nCHANGED COEFFICIENT NUMBER %d ", i);
            printf("\n");
            printf("\nNEW TRUTH TABLE");
            printf("\n");
            for (int k = 0; k < size; ++k) {
                printf("%d ", ftemp[k]);
            }
            int *farr = HadamardCoefficients(ftemp, size, count);
            printf("\nNEW HADAMARD COEFFICIENTS");
            printf("\n");
            for (int l = 0; l < size; ++l) {
                printf("%d ", farr[l]);
            }
            int max = HadamardMax(farr, size);
            //printf("\n max = %d", max);
            int nl = HadamardNLinearity(max, count);
            printf("\n");
            printf("\nNEW HADAMARD NON LINEARITY = %d", nl);
            printf("\n");
            free(farr);
            return ftemp;
            break;
        }
    }
}

//Функція циклічного підвищення нелінійності функції методом Градієнтного Підйому, поки це можливо

int *roundableHillClimbing(const int f[], int size, int count) {
    int *result = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        result[i] = f[i];
    }
    int counter = 0;
    while (counter < 1) {
        int weight;
        weight = HammingWeight(result, size);
        int flag = funcIsBalanced(weight, count);
        printf("\n");
        printf("\nTRUTH TABLE");
        printf("\n");
        for (int i = 0; i < size; ++i) {
            printf("%d ", result[i]);
        }
        int *fxarr = HadamardCoefficients(result, size, count);
        printf("\nHADAMARD COEFFICIENTS");
        printf("\n");
        for (int i = 0; i < size; ++i) {
            printf("%d ", fxarr[i]);
        }
        int max1 = HadamardMax(fxarr, size);
        //printf("\n max = %d", max1);
        int nl2 = HadamardNLinearity(max1, count);
        printf("\n");
        printf("\nHADAMARD NON LINEARITY = %d", nl2);
        printf("\n");

        int sizeWHT1P = 0;
        for (int i = 0; i < size; ++i) {
            if (fxarr[i] == max1) {
                sizeWHT1P++;
            }
        }

        printf("\nW1 PLUS");
        printf("\n");
        int *WHT1Plus = WHT1PlusSet(fxarr, size, sizeWHT1P, max1);
        if (WHT1Plus) {
            for (int i = 0; i < sizeWHT1P; ++i) {
                printf("%d ", WHT1Plus[i]);
            }
        } else {
            printf("NULL");
        }
        printf("\n");

        int sizeWHT1M = 0;
        for (int i = 0; i < size; ++i) {
            if (fxarr[i] == -max1) {
                sizeWHT1M++;
            }
        }

        printf("\nW1 MINUS");
        printf("\n");
        int *WHT1Minus = WHT1MinusSet(fxarr, size, sizeWHT1M, max1);
        if (WHT1Minus) {
            for (int i = 0; i < sizeWHT1M; ++i) {
                printf("%d ", WHT1Minus[i]);
            }
        } else {
            printf("NULL");
        }
        printf("\n");

        int sizeWHT2P = 0;
        for (int i = 0; i < size; ++i) {
            if (fxarr[i] == (max1 - 2)) {
                sizeWHT2P++;
            }
        }

        printf("\nW2 PLUS");
        printf("\n");
        int *WHT2Plus = WHT2PlusSet(fxarr, size, sizeWHT2P, max1);
        if (WHT2Plus) {
            for (int i = 0; i < sizeWHT2P; ++i) {
                printf("%d ", WHT2Plus[i]);
            }
        } else {
            printf("NULL");
        }
        printf("\n");

        int sizeWHT2M = 0;
        for (int i = 0; i < size; ++i) {
            if (fxarr[i] == (max1 - 2)) {
                sizeWHT2M++;
            }
        }

        printf("\nW2 MINUS");
        printf("\n");
        int *WHT2Minus = WHT2MinusSet(fxarr, size, sizeWHT2M, max1);
        if (WHT2Minus) {
            for (int i = 0; i < sizeWHT2M; ++i) {
                printf("%d ", WHT2Minus[i]);
            }
        } else {
            printf("NULL");
        }
        printf("\n");

        // Îòðèìàííÿ îá' ºäíàííÿ WHT1P òà WHT2P
        if (!WHT1Plus && !WHT2Plus) {
            printf("SET WHT PLUS IS NULL");
        } else {
            int c1[(sizeWHT1P + sizeWHT2P)];
            //printf("%d ", (sizeWHT1P + sizeWHT1P));

            int m1 = arrayUnion(WHT1Plus, sizeWHT1P, WHT2Plus, sizeWHT2P, c1);
            printf("\nSET WHT PLUS");
            printf("\n");
            for (int i = 0; i < m1; ++i) {
                printf("%d ", c1[i]);
            }
        }

        printf("\n");

        // Îòðèìàííÿ îá' ºäíàííÿ WHT1M òà WHT2M
        if (!WHT1Minus && !WHT2Minus) {
            printf("\nSET WHT MINUS IS NULL");
        } else {
            int c2[(sizeWHT1M + sizeWHT2M)];
            //printf("%d ", (sizeWHT1P + sizeWHT1P));

            int m2 = arrayUnion(WHT1Minus, sizeWHT1M, WHT2Minus, sizeWHT2M, c2);
            printf("\nSET WHT MINUS");
            printf("\n");
            for (int i = 0; i < m2; ++i) {
                printf("%d ", c2[i]);
            }
        }

        printf("\n");

        /*int *ar7 = linearFunctions(size, n, 5);
        printf("\nLINEAR FUNCTION");
        printf("\n");
        for (int i = 0; i < size; ++i) {
            printf("%d ", ar7[i]);
        }
        printf("\n");*/

        int c1[(sizeWHT1P + sizeWHT2P)];
        int c2[(sizeWHT1M + sizeWHT2M)];
        int m1 = arrayUnion(WHT1Plus, sizeWHT1P, WHT2Plus, sizeWHT2P, c1);
        int m2 = arrayUnion(WHT1Minus, sizeWHT1M, WHT2Minus, sizeWHT2M, c2);

        //printf("%d ", m1);
        //printf("%d ", m2);

        int linearMassSize = m1 + m2;
        /*int c3[1] = {7};
        int c[linearMassSize];
        for (int i = 0; i < m1; ++i) {
                c[i] = c1[i];
        }
        if (m2!=0) {
            for (int j = 0; j < m2; ++j) {
                c[j + m1] = c3[j];
            }
        }*/

        int *c = arrayAdd(c1, m1, c2, m2);
        printf("Linear mass size %d ", linearMassSize);
        printf("\nOMEGA LINEAR FUNCTIONS TO FIND");
        printf("\n");
        for (int i = 0; i < linearMassSize; ++i) {
            printf("%d ", c[i]);
        }
        printf("\n");

        int *linearFunctionsMass = calloc(linearMassSize * size, sizeof(int));
        for (int i = 0; i < linearMassSize; ++i) {
            int t = c[i];
            int *arr = linearFunctions(size, count, t);
            for (int j = 0; j < size; ++j) {
                //printf("%d ", arr[j]);
                linearFunctionsMass[i * size + j] = arr[j];
                printf("%d ", linearFunctionsMass[j]);
            }
        }

        printf("\nLINEAR FUNCTIONS");
        printf("\n");

        for (int i = 0; i < linearMassSize; ++i) {
            for (int j = 0; j < size; ++j) {
                printf("%d ", linearFunctionsMass[i * size + j]);
            }
            printf("\n");
        }


        printf("\nIMPROVEMENT SET:");
        int *ar8 = improvementSet(result, linearFunctionsMass, size, linearMassSize, m1);
        int k = 0;
        printf("\n");
        for (int j = 0; j < size; ++j) {
            printf("%d ", ar8[j]);
            if (ar8[j] != 0) {
                k++;
            }
        }
        if (k == 0) {
            counter = 1;
            //printf("counter %d ", counter);
            int *nonLin = calloc(1, sizeof(int));
            nonLin[0] = nl2;
            return nonLin;
            break;
        }

        int *ar9 = HillClimbing(result, ar8, size, count);
        printf("\n");
        for (int j = 0; j < size; ++j) {
            result[j] = ar9[j];
            //printf("%d ", result[j]);
        }
        free(fxarr);
        free(WHT1Plus);
        free(WHT1Minus);
        free(WHT2Plus);
        free(WHT2Minus);
        free(c);
        free(linearFunctionsMass);
        free(ar8);
        free(ar9);
    }

    return result;
}

//Функція перетворення вхідного S-Box на набір булевих функцій, що його описують

int *SBoxToBooleanFunc(int *sbox, int size, int count) {
    //printf("\nS-BOX\n");
    /*for (int i = 0; i < size; ++i) {
        printf("%d ", sbox[i]);
    }*/
    //printf("\n");
    //printf("\nS-BOX IN BOOLEAN FUNCTIONS REPRESENTATION\n");
    int *result = binaryElements(sbox, size, count);
    /*for (int i = 0; i < count; ++i) {
        printf("Function %d = ", i + 1);
        for (int j = 0; j < size; ++j) {
            printf("%d ", result[i * size + j]);
        }
        printf("\n");
    }*/

    //printf("\n");

    /*for (int i = 0; i < count; ++i) {
         int *temp = calloc(size, sizeof(int));
         //printf("Function %d", i);
         for (int j = 0; j < size; ++j) {
             temp[j] = result[i * size + j];
         }
         int weight = HammingWeight(temp, size);
         int flag = funcIsBalanced(weight, count);
         //printf("\n");
         free(temp);
     }*/
    return result;
}

//Функція перетворення набору булевих функцій на S-Box

int *booleanFunctionsToSBox(const int *arr, int size, int count) {
    int *result = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < count; ++j) {
            result[i] += arr[j * size + i] * raiseToPower(2, j);
        }
    }
    return result;
}

//Функція знаходження показників булевих функцій S-Box'у

int *propertiesOfBooleanFunc(int *arr, int size, int count) {
    printf("\nFUNCTIONS PROPERTIES\n");
    for (int i = 0; i < count; ++i) {
        int *temp = calloc(size, sizeof(int));
        printf("\nFunction %d", i);
        for (int j = 0; j < size; ++j) {
            temp[j] = arr[i * size + j];
        }
        int weight = HammingWeight(temp, size);
        int flag = funcIsBalanced(weight, count);
        int *fxarr = HadamardCoefficients(temp, size, count);
        printf("\nHADAMARD COEFFICIENTS");
        printf("\n");
        for (int q = 0; q < size; ++q) {
            printf("%d ", fxarr[q]);
        }
        int max1 = HadamardMax(fxarr, size);
        //printf("\n max = %d", max1);
        int nl2 = HadamardNLinearity(max1, count);
        printf("\n");
        printf("\nHADAMARD NON LINEARITY = %d", nl2);
        printf("\n");
        int k = 1;
        int ec = expansionCriterion(temp, size, k);
        printf("\n");
        int *ar = autoCorrelation(temp, size, count);

        printf("\nAUTO CORRELATING FUNCTION");
        printf("\n");
        for (int w = size - 1; w >= 0; w--) {
            printf("%d ", ar[w]);
        }
        printf("\n");

        int AC = autoCorrelationMax(ar, size);
        printf("\nAUTO CORRELATION = %d", AC);
        printf("\n");
        int dec = algebraicDeg(temp, size, count);
        printf("\nALGEBRAIC DEGREE = %d ", dec);
        printf("\n");
    }
    return arr;
}

//Функція знаходження лінійних комбінацій для булевих функцій S-Box'у

int *linearCombinations(const int *arr, int size, int count) {
    int *result = calloc(size*(size-1), sizeof(int));
    int *calc = calloc(size, sizeof(int));
    for (int i = 1; i < size; ++i) {
        int *bin = valueToBinary(i, count);
        for (int j = 0, k = count - 1; j < count, k >= 0; ++j, k--) {
            if (bin[k] == 1) {
                for (int w = 0; w < size; ++w) {
                    calc[w] = calc[w] ^ arr[j * size + w];
                    //printf(" %d", arr[j*size]);
                    //printf(" %d", j * size + k);
                    //printf("calc =  %d", calc[k]);
                    //result[(i-1)*size+k] = calc[k];
                    //printf("result  =  %d", (i-1)*size+k);
                }
                //printf("\n");
            }
            for (int r = 0; r < size; ++r) {
                result[(i - 1) * size + r] = calc[r];
            }
            //printf(" %d", bin[j]);
        }
        for (int l = 0; l < size; ++l) {
            //printf("calc =  %d", calc[l]);
            //result[(i-1) * size + l] = calc[l];
            calc[l] = 0;
        }
        //printf("\n");
        free(bin);
    }
    free(calc);
    return result;
}

//Функція знаходження показників лінійних комбінацій для булевих функцій S-Box'у та знаходження мінімальної нелінійності серед них

int *propertiesOfLinearCombinations(const int *arr, int size, int count) {
    int *minimalNL = calloc(size - 1, sizeof(int));
    int *maxAC = calloc(size - 1, sizeof(int));
    int *minDEC = calloc(size - 1, sizeof(int));
    int *result = calloc(4, sizeof(int));
    int balancedFlag = 1;
    //printf("\nLINEAR COMBINATIONS PROPERTIES\n");
    for (int i = 0; i < size - 1; ++i) {
        int *temp = calloc(size, sizeof(int));
        //printf("\nCombination %d", i + 1);
        for (int j = 0; j < size; ++j) {
            temp[j] = arr[i * size + j];
        }
        int weight = HammingWeight(temp, size);
        int flag = funcIsBalanced(weight, count);
        if (flag == balancedFlag) {
        } else {
            balancedFlag = flag;
        }
        int *fxarr = HadamardCoefficients(temp, size, count);
        /*printf("\nHADAMARD COEFFICIENTS");
        printf("\n");
        for (int q = 0; q < size; ++q) {
            printf("%d ", fxarr[q]);
        }*/
        int max1 = HadamardMax(fxarr, size);
        //printf("\n max = %d", max1);
        int nl2 = HadamardNLinearity(max1, count);
        /*printf("\n");
        printf("\nHADAMARD NON LINEARITY = %d", nl2);
        printf("\n");*/
        minimalNL[i] = nl2;
        int k = 1;
        //int ec = expansionCriterion(temp, size, k);
        //printf("\n");
        int *ar = autoCorrelation(temp, size, count);

        /*printf("\nAUTO CORRELATING FUNCTION");
        printf("\n");
        for (int w = size - 1; w >= 0; w--) {
            printf("%d ", ar[w]);
        }
        printf("\n");*/

        int AC = autoCorrelationMax(ar, size);
        //printf("\nAUTO CORRELATION = %d", AC);
        //printf("\n");
        maxAC[i] = AC;
        int dec = algebraicDeg(temp, size, count);
        //printf("\nALGEBRAIC DEGREE = %d ", dec);
        //printf("\n");
        minDEC[i] = dec;
        free(temp);
        free(fxarr);
        free(ar);
    }
    int min = 0;
    min = minimalNL[0];
    //printf("\nNON-LINEARITIES ARRAY");
    //printf("\n");
    for (int r = 0; r < size - 1; ++r) {
        //printf("%d ", minimalNL[r]);
        if (minimalNL[r] < min) {
            min = minimalNL[r];
        }
    }
    int max = 0;
    max = maxAC[0];
    //printf("\nAC ARRAYS");
    //printf("\n");
    for (int t = 0; t < size - 1; ++t) {
        //printf("%d ", maxAC[t]);
        if (maxAC[t] > max) {
            max = maxAC[t];
        }
    }
    int minD = 0;
    minD = minDEC[0];
    //printf("\nDEC ARRAY");
    //printf("\n");
    for (int y = 0; y < size - 1; ++y) {
        //printf("%d ", minDEC[y]);
        if (minDEC[y] < minD) {
            minD = minDEC[y];
        }
    }
    printf("\n");
    result[0] = min;
    result[1] = max;
    result[2] = minD;
    result[3] = balancedFlag;
    free(minimalNL);
    free(maxAC);
    free(minDEC);
    return result;
}

//Функція генерації S-Box'у

int *SBoxGenerating(int n, int m) {
    int size = raiseToPower(2, n);
    int *dec = calloc(size, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size;) {
        dec[i] = rand() % size;
        int contains = 0;
        for (int j = 0; j < i; ++j) {
            if (dec[i] == dec[j]) {
                contains = 1;
                break;
            }
        }
        if (!contains) {
            i++;
        }
    }
    printf("Generated s-box: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ,", dec[i]);
    }
    printf("\n");
    int *sb = SBoxToBooleanFunc(dec, size, m);
    free(dec);
    return sb;
}

//Функція знаходження властивойстей S-Box'у

int *propertiesOfSBox(int *sbox, int size, int count) {
    int result;
    int *ar1 = linearCombinations(sbox, size, count);
    int *ar2 = propertiesOfLinearCombinations(ar1, size, count);
    printf("\nNON LINEARITY OF S-BOX IS\n");
    printf("%d ", ar2[0]);
    printf("\nAUTO CORRELATION OF S-BOX IS\n");
    printf("%d ", ar2[1]);
    printf("\nDEGREE OF S-BOX IS\n");
    printf("%d ", ar2[2]);
    //printf("%d ", ar2[3]);
    if (ar2[3] == 1) {
        printf("\nS-BOX IS BALANCED\n");
        result = 1;
    } else {
        printf("\nS-BOX IS NOT BALANCED\n");
        result = 1;
    }
    printf("\n");
    return ar2;
}

//Функція знаходження нелінійності S-Box'у

int NLOfSBox(const int *sbox, int size, int count) {
    int result;
    int *ar1 = linearCombinations(sbox, size, count);
    result = NLOfLinearCombinations(ar1, size, count);
    free(ar1);
    return result;
}

//Функція знаходження автокореляції S-Box'у

int ACOfSBox(int *sbox, int size, int count) {
    int result;
    int *ar1 = linearCombinations(sbox, size, count);
    int *ar2 = propertiesOfLinearCombinations(ar1, size, count);
    result = ar2[1];
    free(ar1);
    free(ar2);
    return result;
}

//Функція "вартості" S-Box'у

int costFunction(int *sbox, int size, int count) {
    int *costArray = calloc(size - 1, sizeof(int));
    int *ar1 = linearCombinations(sbox, size, count);
    for (int i = 0; i < size - 1; ++i) {
        int *temp = calloc(size, sizeof(int));
        //printf("\nCombination %d", i+1);
        for (int j = 0; j < size; ++j) {
            temp[j] = ar1[i * size + j];
        }
        int *fxarr = HadamardCoefficients(temp, size, count);
        /*printf("\nHADAMARD COEFFICIENTS");
        printf("\n");
        for (int q = 0; q < size; ++q) {
            printf("%d ", fxarr[q]);
        }*/
        int max1 = HadamardMax(fxarr, size);
        //printf("\n max = %d", max1);
        costArray[i] = max1;
        free(fxarr);
        free(temp);
    }
    int cost;
    cost = costArray[0];
    //printf("\n");
    //printf("\nCOST ARRAY");
    //printf("\n");
    for (int t = 0; t < size - 1; ++t) {
        if (costArray[t] > cost) {
            cost = costArray[t];
        }
    }
    free(costArray);
    free(ar1);
    return cost;
}

//Функція "вартості" S-Box'у з Picek

long long costFunctionPicek(int *sbox, int size, int count) {
    long long res = 0;
    int X1 = 21;
    int R1 = 7;
    int C [] = {0,4,8,12,16,20,24,28,32};
    //int *costArray = calloc(size - 1, sizeof(int));
    int *ar1 = linearCombinations(sbox, size, count);
    for (int i = 0; i < size - 1; ++i) {
        int *temp = calloc(size, sizeof(int));
        //printf("\nCombination %d", i+1);
        for (int j = 0; j < size; ++j) {
            temp[j] = ar1[i * size + j];
        }
        int *fxarr = HadamardCoefficients(temp, size, count);
        /*printf("\nHADAMARD COEFFICIENTS");
        printf("\n");
        for (int q = 0; q < size; ++q) {
            printf("%d ", fxarr[q]);
        }*/
        for (int j = 0; j < size; ++j) {
            //printf (" %d ", fxarr[j]);
            int w = abs(abs(fxarr[j]) - X1);
            //printf(" %d ", w);
            res += raiseToPowerLong(w, R1);
            //printf("res = %lld ", res);
        }
        free(fxarr);
        free(temp);
    }
    /*int cost;
    cost = costArray[0];
    //printf("\n");
    //printf("\nCOST ARRAY");
    //printf("\n");
    for (int t = 0; t < size - 1; ++t) {
        //printf("%d ", costArray[t]);
        if (costArray[t] > cost) {
            cost = costArray[t];
        }
    }
    free(costArray);*/
    free(ar1);
    return res;
}

//Функція "вартості" S-Box'у з Cuba

long long costFunctionCuba(int *sbox, int size, int count) {
    long long res = 0;
    int X1 = 21;
    int R1 = 7;
    long long calc = 1;
    int C [] = {0,4,8,12,16,20,24,28,32};
    for (int i = 0; i < count; ++i) {
        int *fxarr = HadamardCoefficients(sbox + i * size, size, count);
        /*printf("\nHADAMARD COEFFICIENTS");
        printf("\n");
        for (int q = 0; q < size; ++q) {
            printf("%d ", fxarr[q]);
        }*/
        for (int j = 0; j < size; ++j) {
            //printf (" %d ", fxarr[j]);
            for (int k = 0; k < 9; ++k){
                long long w = abs(abs(fxarr[j]) - C[k]);
                //printf("w=  %d ", w);
                calc = calc*w;
                //printf("calc=  %d ", calc);
            }
            //printf(" %d ", w);
            res += calc;
            calc = 1;
            //printf("res = %lld ", res);
        }
        //printf("\n");
        free(fxarr);
    }
    /*int cost;
    cost = costArray[0];
    //printf("\n");
    //printf("\nCOST ARRAY");
    //printf("\n");
    for (int t = 0; t < size - 1; ++t) {
        //printf("%d ", costArray[t]);
        if (costArray[t] > cost) {
            cost = costArray[t];
        }
    }
    free(costArray);*/
    return res;
}

//Функція "вартості" S-Box'у з Cuba (розрахунок за лінійними комбінаціями)

long long costFunctionCubaLinComb(int *sbox_d, int size, int count) {
    long long res = 0;
    long long calc = 1;
    int C [] = {0,4,8,12,16,20,24,28,32};
    int *sbox_b = SBoxToBooleanFunc(sbox_d,size,count);
    int *ar1 = linearCombinations(sbox_b, size, count);
    for (int i = 0; i < size - 1; ++i) {
        int *temp = calloc(size, sizeof(int));
        for (int j = 0; j < size; ++j) {
            temp[j] = ar1[i * size + j];
        }
        int *fxarr = HadamardCoefficients(temp, size, count);
        /*printf("\nHADAMARD COEFFICIENTS");
        printf("\n");
        for (int q = 0; q < size; ++q) {
            printf("%d ", fxarr[q]);
        }*/
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < 9; ++k){
                long long w = abs(abs(fxarr[j]) - C[k]);
                calc = calc*w;
            }
            res += calc;
            calc = 1;
        }
        free(fxarr);
        free(temp);
    }
    free(ar1);
    return res;
}

//Функція "вартості" WHS

long long costFunctionWHS(int *sbox, int size, int count) {
    long long res = 0;
    int X1 = 21;
    int R1 = 7;
    long long calc = 1;
    for (int i = 0; i < count; ++i) {
        int *fxarr = HadamardCoefficients(sbox + i * size, size, count);
        /*printf("\nHADAMARD COEFFICIENTS");
        printf("\n");
        for (int q = 0; q < size; ++q) {
            printf("%d ", fxarr[q]);
        }*/
        for (int j = 0; j < size; ++j) {
            printf (" %d ", fxarr[j]);
            int w = abs(abs(fxarr[j]) - X1);
            //printf(" %d ", w);
            res += raiseToPowerLong(w, R1);
            //printf("res = %lld ", res);
        }
        printf("\n");
        free(fxarr);
    }
    /*int cost;
    cost = costArray[0];
    //printf("\n");
    //printf("\nCOST ARRAY");
    //printf("\n");
    for (int t = 0; t < size - 1; ++t) {
        //printf("%d ", costArray[t]);
        if (costArray[t] > cost) {
            cost = costArray[t];
        }
    }
    free(costArray);*/
    return res;
}

//Реалізація "Імітації Відпалу"

int *simulatedAnnealing(const int *sbox, int size, int count) {
    char *filename = "D:\\CLionProjects\\boolANF\\result.txt";
    FILE *fp;
    double T = 100;
    double a = 0.99;
    int MIL = 100;
    int MUL = 0;
    int SNL = 0;
    int flag;
    int fileCounter = 0;
    int NLStart = NLOfSBox(sbox, size, count);
    printf("NLStart ===%d ", NLStart);
    int *SBoxBest = calloc(size, sizeof(int));
    int *SB = calloc(size * count, sizeof(int));
    int *SY = calloc(size * count, sizeof(int));
    SBoxBest = booleanFunctionsToSBox(sbox, size, count);
    for (int i = 0; i < size; ++i) {
        //printf("%d ", SBoxBest[i]);
    }
    int *S = calloc(size, sizeof(int));
    for (int j = 0; j < size; ++j) {
        S[j] = SBoxBest[j];
    }
    int first = rand() % (size);
    int second = rand() % (size);
    int counter = 0;
    int *Y = calloc(size, sizeof(int));
    while (SNL < 100) {
        counter++;
        for (int b = 0; b < MIL; ++b) {
            printf("%d ", b);
            if (first == second) {
                first = (first + rand() % (size)) % size;
            }
            srand(time(NULL));
            SB = SBoxToBooleanFunc(S, size, count);
            /*for (int i = 0; i < size*count; ++i) {
                printf("%d ", SB[i]);
            }*/
            int costOfPrevious = costFunction(SB, size, count);
            printf("COST OF OLD ===%d ", costOfPrevious);
            //int NLofS = NLOfSBox(SB, size, count);
            //printf("NL OF OLD ===%d ", NLofS);
            printf("\n");
            //printf("First = %d ", first);
            //printf("Second = %d ", second);
            for (int k = 0; k < size; ++k) {
                Y[k] = S[k];
            }
            int tmp = Y[first];
            Y[first] = Y[second];
            Y[second] = tmp;
            first = (first + Y[second]) % size;
            second = (second + Y[first]) % size;
            SY = SBoxToBooleanFunc(Y, size, count);
            int costOfNew = costFunction(SY, size, count);
            printf("COST OF NEW ===%d ", costOfNew);
            //int NLofNS = NLOfSBox(SY, size, count);
            //printf("NL OF NEW ===%d ", NLofNS);
            int delta = costOfNew - costOfPrevious;
            //printf("\nDelta ===%d ", delta);
            if (delta <= 0) {
                for (int l = 0; l < size * count; ++l) {
                    SB[l] = SY[l];
                    MUL = 0;
                    //printf("SB [j] ===%d ", SB[j]);
                }
            } else {
                ++MUL;
                //ãåíåðèðóåì ñëó÷àéíîå ÷èñëî 0..1
                srand(time(NULL));
                int N = 100;
                int rd = rand() % (N);
                //printf("\nrd ===%d ", rd);
                double u = (double) rd / N;
                //printf("\nu ===%lf\n ", u);
                double t = (double) delta / T;
                //printf("\ndt ===%lf\n ", exp(-t));
                if (u < exp(-t)) {
                    //printf("\nDT\n");
                    //ñ íåêîé âåðîÿòíîñòüþ ïðèíèìàåì õóäøåãî ïîòîìêà
                    for (int m = 0; m < size * count; ++m) {
                        SB[m] = SY[m];
                    }
                }
            }
            S = booleanFunctionsToSBox(SB, size, count);
            if (costOfNew <= 60) {
                ++fileCounter;
                if ((fp = fopen(filename, "a")) == NULL) {
                    printf("Error while opening file");
                }
                // записываем строку
                fprintf(fp, "\nS-BOX NUMBER");
                fprintf(fp, " %d:", fileCounter);
                for (int p = 0; p < size; ++p) {
                    fprintf(fp, "%d, ", S[p]);
                }
                fprintf(fp, "\n");
                fprintf(fp, "\nCOST OF S-BOX");
                fprintf(fp, " %d:", costOfNew);
                fprintf(fp, "\n");
                fprintf(fp, "\n");
                fclose(fp);   //закрываем файл
            }
            if (costOfNew <= 56) {
                break;
            }
            //printf("MUL ===%d ", MUL);
            if (MUL >= 30) {
                break;
            }
        }
        MUL = 0;
        T = T * a;
        /*for (int j = 0; j < size * count; ++j) {
            printf("%d ", SB[j]);
        }*/
        SNL = NLOfSBox(SB, size, count);
        printf("\nSNL ===%d ", SNL);
        printf("\nTemperature ===%lf ", T);
        printf("\nC==%d\n", counter);
        /*int SAC = ACOfSBox(SB, size, count);
        printf("SAC ===%d ", SAC);*/
    }
    free(Y);
    free(SY);
    free(SBoxBest);
    free(SB);
    return S;
}

//Функція знаходження мінімальної нелінійності серед лінійних комбінацій

int NLOfLinearCombinations(const int *arr, int size, int count) {
    int *minimalNL = calloc(size - 1, sizeof(int));
    int result;
    int *temp = calloc(size, sizeof(int));
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size; ++j) {
            temp[j] = arr[i * size + j];
        }
        int *fxarr = HadamardCoefficients(temp, size, count);
        int max1 = HadamardMax(fxarr, size);
        int nl2 = HadamardNLinearity(max1, count);
        minimalNL[i] = nl2;
        free(fxarr);
    }
    int min = 0;
    min = minimalNL[0];
    //printf("\nNON-LINEARITIES ARRAY");
    //printf("\n");
    for (int r = 0; r < size - 1; ++r) {
        //printf("%d ", minimalNL[r]);
        if (minimalNL[r] < min) {
            min = minimalNL[r];
        }
    }
    result = min;
    free(minimalNL);
    free(temp);
    return result;
}

//Функція знаходження дельта-рівномірності

int deltaUniformity(const int *arr, int size, int count) {
    int result;
    int max = 0;
    for (int a = 1; a < size; ++a) {
        for (int b = 0; b < size; ++b) {
            result = 0;
            for (int x = 0; x < size; ++x) {
                if ((arr[x] ^ arr[x ^ a]) == b) {
                    ++result;
                }
            }
            if (result > max) {
                max = result;
            }
        }

    }
    return max;
}

//Функція знаходження DDT та її максимуму

int differenceTableMax(const int *sbox, int size) {
    int *DDT = calloc(size * size, sizeof(int));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            DDT[i * size + j] = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            DDT[(i ^ j) * size + (sbox[i] ^ sbox[j])]++;
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", DDT[i * size + j]);
        }
        printf("\n");
    }
    int *findMax = DDT;
    int result = 0;
    for (int i = 1; i < size * size; i++) {
        if (findMax[i] > result)
            result = findMax[i];
    }
    free(DDT);
    free(findMax);
    return result;
}

int *binaryElementsApprox(int *arr, int size, int count) {
    int *result = calloc(size * count, sizeof(int));
    for (int i = 0; i < size; ++i) {
        int *bin = valueToBinary(arr[i], count);
        for (int j = count - 1; j >= 0; j--) {
            result[j * size + i] = bin[j];
        }
        free(bin);
    }
    return result;
}

int *SBoxApprox(int *sbox, int size, int count) {
    int *result = binaryElementsApprox(sbox, size, count);
    return result;
}

//Функція знаходження LAT та її максимуму

int LATMax(int *sbox, int size, int count) {
    int *ar = SBoxApprox(sbox, size, count);
    int *elems = elemsForN(size);
    int *binelems = binaryElementsApprox(elems, size, count);
    int *temp = calloc(size, sizeof(int));
    int *temp2 = calloc(size, sizeof(int));
    int *coefficients = calloc(size * size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        int *bin1 = valueToBinary(i, count);
        for (int k = count - 1; k >= 0; k--) {
            if (bin1[k]) {
                //printf("K===%d ",k);
                //printf("X == \n ");
                for (int l = 0; l < size; ++l) {
                    temp[l] = temp[l] ^ binelems[k * size + l];
                    //printf("%d ",temp[l]);
                }
                //printf("\n ");
            }
        }
        //printf("\n ");
        for (int j = 0; j < size; ++j) {
            int *bin2 = valueToBinary(j, count);
            for (int q = count - 1; q >= 0; q--) {
                if (bin2[q]) {
                    //printf("K===%d ",k);
                    //printf("\nY [%d]== \n ", j);
                    for (int w = 0; w < size; ++w) {
                        temp2[w] = temp2[w] ^ ar[q * size + w];
                        //printf("%d ",temp2[l]);
                    }
                }
            }
            //printf("\n ");
            int calc = 0;
            for (int r = 0; r < size; ++r) {
                temp2[r] = temp2[r] ^ temp[r];
                //printf("%d ", temp2[l]);
                if (temp2[r] == 0) {
                    ++calc;
                }
                temp2[r] = 0;
            }
            int result = 0;
            result = calc - (size / 2);
            //printf("COEFFS = %d ", result);
            coefficients[i * size + j] = result;
            free(bin2);
        }
        for (int t = 0; t < size; ++t) {
            temp[t] = 0;
        }
        //printf("\n ");
        free(bin1);
    }
    for (int n = 0; n < size; ++n) {
        for (int m = 0; m < size; ++m) {
            //printf("%d ", coefficients[n*size+m]);
        }
        //printf("\n");
    }
    int result = 0;
    for (int p = 1; p < size * size; p++) {
        if (abs(coefficients[p]) > result)
            result = abs(coefficients[p]);
    }
    free(ar);
    free(elems);
    free(binelems);
    free(temp);
    free(temp2);
    free(coefficients);
    return result;
}

//Функція знаходження циклічної структури

int cyclicStructure(const int *sbox, int size) {
    int *structure = calloc(size * 4, sizeof(int));
    int *indAr = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        indAr[i] = 0;
    }
    structure[0] = 0;
    int curInd = -99;
    while (1) {
        curInd = -99;
        for (int i = 0; i < size; i++) {
            if (indAr[i] != 1) {
                curInd = i;
                break;
            }

        }
        if (curInd == -99)
            break;
        int lenght = 0;
        int position = curInd;
        while (indAr[position] != 1) {
            indAr[position] = 1;
            position = sbox[position];
            lenght++;
        }

        structure[structure[0] * 2 + 1] = curInd;
        structure[structure[0] * 2 + 2] = lenght;
        structure[0]++;
    }
    int max = 0;
    max = structure[structure[0] - 1 * 2 + 2];
    for (int i = structure[0] - 1; i >= 0; i--) {
        //printf("%d:%d, ", structure[i * 2 + 1], structure[i * 2 + 2]);
        if (structure[i * 2 + 2] > max) {
            max = structure[i * 2 + 2];
        }
    }
    free(structure);
    free(indAr);
    return max;
}

//Функція знаходження фіксованих точок

int fixedPoints(const int *sbox, int size) {
    int counter = 0;
    for (int i = 0; i < 256; i++)
        if (sbox[i] == i || sbox[i] == ~i) {
            counter++;
        }
    /*if (counter > 0)
        printf("\nCapacity of fixed points: %d", counter);
    else
        printf("\nFixed points ain't found\n");*/

    return counter;
}

//Функція знаходження мінімального ступеня

int minDegCalculation(const int *arr, int size, int count) {
    int *minDEC = calloc(size - 1, sizeof(int));
    int result = 0;
    int *temp = calloc(size, sizeof(int));
    for (int i = 0; i < size - 1; ++i) {
        //printf("\nCombination %d", i + 1);
        for (int j = 0; j < size; ++j) {
            temp[j] = arr[i * size + j];
        }
        int dec = algebraicDeg(temp, size, count);
        //printf("\nALGEBRAIC DEGREE = %d ", dec);
        //printf("\n");
        minDEC[i] = dec;
    }
    int minD = 0;
    minD = minDEC[0];
    //printf("\nDEC ARRAY");
    //printf("\n");
    for (int y = 0; y < size - 1; ++y) {
        //printf("%d ", minDEC[y]);
        if (minDEC[y] < minD) {
            minD = minDEC[y];
        }
    }
    result = minD;
    free(minDEC);
    free(temp);
    return result;
}

//Знаходження мінімально ступеня з попередньої функції

int minDegree(int *sbox, int size, int count) {
    int *ar = SBoxToBooleanFunc(sbox, size, count);
    int *ar2 = linearCombinations(ar, size, count);
    int result = minDegCalculation(ar2, size, count);
    free(ar);
    free(ar2);
    return result;
}

//Функція побудування одного рядка матриці, що описує S-Box

void buildOneRow(int *arr, int *monomials) {
    monomials[0] = 1;
    //monomials x1,x8,y1,...,y8
    for (int i = 1; i <= 16; i++)
        monomials[i] = arr[i - 1];
    int pos = 17;
    //monomials x1x2
    for (int i = 1; i < 16; i++) {
        for (int j = i + 1; j <= 16; j++) {
            monomials[pos] = monomials[i] & monomials[j];
            pos++;
        }
    }
    //monomials x1x2x3
    for (int i = 1; i < 15; i++) {
        for (int j = i + 1; j <= 16; j++) {
            for (int k = j + 1; k <= 16; k++) {
                monomials[pos] = monomials[i] & monomials[j] & monomials[k];
                pos++;
            }
        }
    }
}

//Функція обчислення рангу матриці

int rankCalculation(int rows, int cols, int arr[rows][cols]) {
    int m = cols;
    int n = rows;

    int rank = cols;
    int *line = calloc(cols, sizeof(int));
    for (int q = 0; q < cols; q++)
        line[q] = 0;
    for (int i = 0; i < m; ++i) {
        int j;
        for (j = 0; j < n; ++j)
            if (!line[j] && arr[j][i])
                break;
        if (j == n)
            --rank;
        else {
            line[j] = 1;
            for (int k = 0; k < n; ++k)
                if (k != j && arr[k][i])
                    for (int p = i + 1; p < m; ++p)
                        arr[k][p] ^= arr[j][p] & arr[k][i];
        }
    }
    free(line);
    return rank;
}

//Функція обчислення алгебраїчного імунітету

int algebraicImmunity(const int *sbox, int size, int count) {
    int rows = raiseToPower(2, count);
    int calc = 0;
    int cols = 0;
    int result = 0;
    for (int d = 0; d < count; ++d) {
        calc = numOfCombinations(count + count, d);
        cols = cols + calc;
        if (cols > rows) {
            result = d;
            break;
        }
    }
    //printf("\n num of comb %d \n", cols);
    int mat[rows][cols];
    int tmp[cols];
    int values[count + count];
    int *input_values = calloc(size * count, sizeof(int));
    for (int i = 0; i < size; ++i) {
        int *bin = valueToBinary(i, count);
        for (int j = 0; j < count; ++j) {
            input_values[i * count + j] = bin[j];
            //printf("%d ", input_values[i*count+j]);
        }
        //printf("\n");
        free(bin);
    }
    for (int i = 0; i < 256; i++) {
        int y = sbox[i];
        values[0] = input_values[i * count + 0];
        values[1] = input_values[i * count + 1];
        values[2] = input_values[i * count + 2];
        values[3] = input_values[i * count + 3];
        values[4] = input_values[i * count + 4];
        values[5] = input_values[i * count + 5];
        values[6] = input_values[i * count + 6];
        values[7] = input_values[i * count + 7];
        values[8] = input_values[y * count + 0];
        values[9] = input_values[y * count + 1];
        values[10] = input_values[y * count + 2];
        values[11] = input_values[y * count + 3];
        values[12] = input_values[y * count + 4];
        values[13] = input_values[y * count + 5];
        values[14] = input_values[y * count + 6];
        values[15] = input_values[y * count + 7];
        buildOneRow((int *) &values, (int *) &mat[i]);
    }
    int rank = rankCalculation(rows, cols, mat);
    free(input_values);
    //printf("%d", rank);
    if (rank == rows) {
        return result;
    } else {
        return result - 1;
    }
}

//Функція знаходження кількості сполучень

int numOfCombinations(int n, int d) {
    if (n == d)
        return 1;
    if (d == 1)
        return n;
    if (d == 0)
        return 1;
    return numOfCombinations(n - 1, d - 1) + numOfCombinations(n - 1, d);
}

//Функція бульбашкового сортування

void bubble_sort(int *data, int size) {
    int i, j;
    for (i = 0; i < size; ++i) {
        for (j = size - 1; j > i; --j) {
            if (data[j] < data[j-1]) {
                int t = data[j - 1];
                data[j - 1] = data[j];
                data[j] = t;
            }
        }
    }
}

//Функція знаходження спектру Уолдша-Адамара для кожної з лінійних комбінацій

int *WHTSpectrumForLinearComb(const int *arr, int size, int count) {
    int *result = calloc(size*(size-1), sizeof(int));
    int *temp = calloc(size, sizeof(int));
    for (int i = 0; i < size - 1; ++i) {
        //printf("\nCombination %d", i + 1);
        for (int j = 0; j < size; ++j) {
            temp[j] = arr[i * size + j];
            //printf("%d ", temp[j]);
        }
        int *fxarr = HadamardCoefficients(temp, size, count);
        for (int g = 0; g< size; ++g){
            fxarr[g] = abs(fxarr[g]);
        }
        bubble_sort(fxarr,size);
        for (int g = 0; g< size; ++g){
            result[i*size+g] = fxarr[g];
        }
        //printf("\nHADAMARD COEFFICIENTS");
        //printf("\n");
        /*for (int q = 0; q < size; ++q) {
            //printf("%d ", fxarr[q]);
            result[i*size+q] = fxarr[q];
        }*/
        free(fxarr);
    }
    free(temp);
    return result;
}

//Функція знаходження автокореляційної функції для кожної з лінійних комбінацій

int *ACForLinearComb(const int *arr, int size, int count) {
    int *result = calloc(size*(size-1), sizeof(int));
    int *temp = calloc(size, sizeof(int));
    for (int i = 0; i < size - 1; ++i) {
        //printf("\nCombination %d", i + 1);
        for (int j = 0; j < size; ++j) {
            temp[j] = arr[i * size + j];
            //printf("%d ", temp[j]);
        }
        int *ar = autoCorrelation(temp, size, count);

        for (int g = 0; g< size; ++g){
            ar[g] = abs(ar[g]);
        }

        bubble_sort(ar,size);
        for (int q = 0; q < size; ++q) {
            //printf("%d ", fxarr[q]);
            result[i*size+q] = ar[q];
        }
        free(ar);
    }
    free(temp);
    return result;
}

//Функція знаходження алгебраїчного ступеня для кожної з лінійних комбінацій

int *DegForLinearComb(const int *arr, int size, int count) {
    int *result = calloc((size-1), sizeof(int));
    int *temp = calloc(size, sizeof(int));
    for (int i = 0; i < size - 1; ++i) {
        //printf("\nCombination %d", i + 1);
        for (int j = 0; j < size; ++j) {
            temp[j] = arr[i * size + j];
            //printf("%d ", temp[j]);
        }
        int dec = algebraicDeg(temp, size, count);
        //printf("\nALGEBRAIC DEGREE = %d ", dec);
        //printf("\n");
        //minDEC[i] = dec;
        result[i] = dec;
    }
    free(temp);
    return result;
}

//Функція знаходження лінійної збитковості S-Box'у

int linearRedundancy(int *sbox, int size, int count, int sp [size-1][size], int ac [size-1][size]) {
    int result;
    int *ar1 = SBoxToBooleanFunc(sbox, size, count);
    //printf("\n1");
    int *ar2 = linearCombinations(ar1, size, count);
    /*for (int i = 0; i < size-1; ++i){
        for(int j = 0; j<size; ++j){
            printf("%d ", sp[i][j]);
        }
        printf("%d ",counter);
        printf("\n");
        counter++;
    }*/
    free(ar1);
    //printf("\n2");
    //int *ar5 = calloc((size-1),sizeof(int));
    //int ar33[size-1][size];
    int *ar3 = WHTSpectrumForLinearComb(ar2, size, count);
    //printf("\n3");
    /*for (int i = 0; i < size*(size-1); ++i){
        printf("%d ", ar3[i]);
    }*/
    int *ar4 = ACForLinearComb(ar2, size, count);
    free(ar2);
    //printf("\n4");
    //ar5 = DegForLinearComb(ar2,size,count);
    for (int b = 0; b < size - 1; ++b) {
        for (int q = 0; q < size; ++q) {
            sp[b][q] = ar3[b * size + q];
        }
    }
    for (int z = 0; z < size - 1; ++z) {
        for (int n = 0; n < size; ++n) {
            ac[z][n] = ar4[z * size + n];
        }
    }
    free(ar3);
    free(ar4);
    /*int dg [size-1];
    for (int i = 0; i < size - 1; ++i) {
        dg[i] = ar5[i];
    }*/
    /*FILE *file;
    fopen_s(&file, "Linear comb and WHT Spectrum.txt", "w");
    if (file == NULL) {
        printf("ERROR: Can't save sbox to file!\n");
        for (;;);
    }
    fprintf(file, "\n");
    for (int i = 0; i < size-1; ++i){
        fprintf(file,"\nLINEAR COMBINATION\n");
        for(int j = 0; j<size; ++j){
            ar33[i][j] = ar2[i*size+j];
            fprintf(file,"%d, ", ar33[i][j]);;
        }
        fprintf(file,"\n");
        fprintf(file,"\nHADAMARD SPECTRUM\n");
        for(int k = 0; k<size; ++k){
            fprintf(file,"%d ", sp[i][k]);
        }
        fprintf(file,"\n");
    }
    fprintf(file, "\n");
    fclose(file);*/

    /*printf("\nHADAMARD SPECTRUM\n");
    for (int i = 0; i < size-1; ++i){
        for(int j = 0; j<size; ++j){
            printf("%d ", sp[i][j]);
        }
        printf("\n");
    }
    printf("\nAUTO CORRELATION FUNCTIONS\n");
    for (int i = 0; i < size-1; ++i){
        for(int j = 0; j<size; ++j){
            printf("%d ", ac[i][j]);
        }
        printf("\n");
    }
    printf("\nDEGREES\n");
    for (int i = 0; i < size-1; ++i){
        printf("%d ", dg[i]);
    }
    printf("\n");*/
    int innerCounter = 0;
    int OuterCounter = 0;
    int finalCounter = 0;
    for (int i = 0; i < size - 1; ++i) {
        for (int h = i + 1; h < size - 1; ++h) {
            for (int j = 0; j < size; ++j) {
                if (i != h) {
                    if (sp[i][j] == sp[h][j] && sp[h][j] != -999 &&
                        (ac[i][j] == ac[h][j] && ac[h][j] != -999) /*(dg[i] == dg[h] && dg[h] != -999)*/) {
                        innerCounter++;
                    }
                }
            }
            //printf("\nInner counter = %d %d %d", i, h,innerCounter);
            /*printf("\n");
            printf("\n");
            for (int j = 0; j < size; ++j){
                printf("%d ", sp[i][j]);
            }
            printf("\n");
            printf("\n");
            for (int j = 0; j < size; ++j) {
                printf("%d ", sp[h][j]);
            }*/
            if (innerCounter == size) {
                //if (i!=h) {
                //if (ar4[i]==ar4[h] && ar5[i] == ar5[h]) {
                //printf("\nSTRINGS ARE EQUAL");
                //dg[h] = -999;
                OuterCounter++;
                for (int d = 0; d < size; ++d) {
                    sp[h][d] = -999;
                    //ac[h][j] = -999;
                    //dg[h] = -999;
                }
                //}
                //}
            }
            innerCounter = 0;
        }
        /*for (int j = 0; j < size; ++j){
            sp[i][j] = -999;
            ac[i][j] = -999;
            dg[i] = -999;
        }*/
        //printf("\nOC ==%d ", OuterCounter);
    }
    /*int counter = 0;
    printf("\nHADAMARD SPECTRUM AFTER\n");
    for (int i = 0; i < size-1; ++i){
        for(int j = 0; j<size; ++j){
            printf("%d ", sp[i][j]);
        }
        printf("%d ",counter);
        printf("\n");
        counter++;
    }*/
    /*printf("\nAUTO CORRELATION FUNCTIONS AFTER\n");
    for (int i = 0; i < size-1; ++i){
        for(int j = 0; j<size; ++j){
            printf("%d ", ac[i][j]);
        }
        printf("\n");
    }
    printf("\nDEGREES AFTER\n");
    for (int i = 0; i < size-1; ++i){
        printf("%d ", dg[i]);
    }*/
    finalCounter = finalCounter + OuterCounter;
    //printf("\nFINAL ==%d ", finalCounter);
    result = (size - 1) - finalCounter;
    return result;
}

//Функція генерації S-Box'у

int *SBoxGeneratingDec(int n, int m, int counter) {
    int size = raiseToPower(2, n);
    int *dec = calloc(size, sizeof(int));
    srand((counter*counter) %size);
    for (int i = 0; i < size;) {
        dec[i] = rand() % size;
        int contains = 0;
        for (int j = 0; j < i; ++j) {
            if (dec[i] == dec[j]) {
                contains = 1;
                break;
            }
        }
        if (!contains) {
            i++;
        }
    }
    /*printf("Generated s-box: ");
    for (int i = 0; i < size; ++i) {
        printf("%d, ", dec[i]);
    }
    printf("\n");*/
    FisherYates(dec,size);
    return dec;
}

//Функція знаходження нелінійності S-Box'у в десятковому вигляді

int NLOfSBoxDec(int *sbox, int size, int count) {
    int result;
    int *ar1 = SBoxToBooleanFunc(sbox,size,count);
    int *ar2 = linearCombinations(ar1, size, count);
    result = NLOfLinearCombinations(ar2, size, count);
    free(ar2);
    return result;
}

//Функція генерації S-Box'у за допомогою методу Рою Часток

int *particleSwarmOptimization(int size, int count, int N, int maxIter, int mode, int *finalIter){
    int flag102 = 0;
    clock_t start = clock();
    srand(time(NULL));
    int iter = 0;
    int flag = rand()%size;
    int population[2*N][size];
    for (int i = 0; i < size; ++i){
        population[0][i] = aesSbox[i];
    }
    for (int q = 1; q < N; ++q){
        int *ar1 = SBoxGeneratingDec(count,count,q+flag);
        for(int w = 0; w < size; ++w) {
            population[q][w] = ar1[w];
        }
        free(ar1);
    }
    int arrNL[N];
    for (int q = 0; q < N; ++q){
        for(int w = 0; w < size; ++w){
            printf("%d ",population[q][w]);
        }
        int LAT = LATMax(population[q],size,count);
        int NL = raiseToPower(2, count - 1) - LAT;
        printf( "\nNon-linearity from LAT = %d \n", NL);
        printf("\n");
        arrNL[q] = NL;
    }
    int g[size];
    for (int i = 0; i < N; ++i) {
        for (int j = N - 1; j > i; --j) {
            if (arrNL[j] > arrNL[j - 1]) {
                int t = arrNL[j - 1];
                arrNL[j - 1] = arrNL[j];
                arrNL[j] = t;
                for (int k = 0; k < size; ++k) {
                    g[k] = population[j - 1][k];
                    population[j - 1][k] = population[j][k];
                    population[j][k] = g[k];
                }
            }
        }
    }
    printf("\n");
    for (int q = 0; q < N; ++q){
        printf( "\n%d ", arrNL[q]);
    }
    printf("\nSORTED BY Non-Linearity\n");
    for (int q = 0; q < N; ++q){
        for(int w = 0; w < size; ++w){
            printf("%d, ",population[q][w]);
        }
        printf("\n\n");
    }
    int gBest[size];
    for (int m = 0; m < size; ++m){
        gBest[m] = population[0][m];
    }
    int pBest[N][size];
    for (int i = 1; i < N; ++i){
        for (int j = 0; j < size; ++j){
            pBest[i-1][j] = population[i][j];
        }
    }
    printf("\n\n");
    printf("\ngBest\n");
    for (int m = 0; m < size; ++m){
        printf("%d, ",gBest[m]);
    }
    printf("\npBest\n");
    for (int q = 0; q < N-1; ++q){
        for(int w = 0; w < size; ++w){
            printf("%d, ",pBest[q][w]);
        }
        printf("\n\n");
    }
    double weight1 = 0.1;
    double weight2 = 1.6;
    double weightCur;
    int curIter = 0;
    int Vel[N][size];
    int arrNLSorted[size];
    while(maxIter > 0) {
        weightCur = weight1+(curIter-1)*((weight2-weight1)/maxIter);
        printf("\nWHILE\n");
        int Q = 100;
        int rd1 = rand() % (Q);
        double xr1 = (double) rd1 / Q;
        double c1 = 2 * xr1;
        int rd2 = rand() % (Q);
        double xr2 = (double) rd2 / Q;
        double c2 = 2 * xr2;
        int rd3 = rand() % (Q);
        double xr3 = (double) rd3 / Q;
        double r1 = xr3;
        int rd4 = rand() % (Q);
        double xr4 = (double) rd4 / Q;
        double r2 = xr4;
        printf("c1 = %lf ", c1);
        printf("c2 = %lf ", c2);
        printf("r1 = %lf ", r1);
        printf("r2 = %lf \n", r2);
        printf("\n\n");
        for (int b = 0; b < N; ++b) {
            arrNLSorted[b] = arrNL[b];
        }
        int tempSbox[size];
        int tempSbox2[size];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < size;) {
                if (mode == 1){
                    Vel[i][j] = ceil(weightCur * Vel[i][j] + c1 * r1 * (gBest[j] - population[i][j] +
                                                                        c2 * r2 * (gBest[j] - population[i][j])));
                }
                if (mode == 0) {
                    Vel[i][j] = ceil(weightCur * Vel[i][j] + c1 * r1 * (pBest[i][j] - population[i][j] +
                                                                        c2 * r2 * (gBest[j] - population[i][j])));
                }
                if (Vel[i][j] < 0) {
                    Vel[i][j] = myModulusDec((Vel[i][j] + 256), 256);
                }
                //printf("Vel[%d][%d] = %d ", i,j,Vel[i][j]);
                int X = myModulusDec((population[i][j] + Vel[i][j]), 256);
                int contains;
                if (contains == 0) {
                    tempSbox[j] = X;
                } else {
                    tempSbox[j] = myModulusDec((tempSbox[j] + rand()), 256);
                    /*if (tempSbox[j] == 0){
                        tempSbox[j] = myModulusDec((tempSbox[j]+rand()),256);
                    }*/
                };
                //printf("\n%d temp box b4 cycle [%d]", tempSbox[j],j);
                contains = 0;
                for (int k = 0; k < j; ++k) {
                    if (tempSbox[k] == tempSbox[j]) {
                        //printf("\n%d k = \n", k);
                        //printf("\n%d j = \n", j);
                        //tempSbox[j] = myModulusDec((tempSbox[j]+rand()),256);
                        //tempSbox2[j] = tempSbox[j];
                        //printf("\n%d j", tempSbox[j]);
                        //printf("\n%d k", tempSbox[k]);
                        contains = 1;
                        break;
                    }
                }
                if (!contains) {
                    j++;
                }
            }
            if (i == 0) {
                int LAT = LATMax(tempSbox, size, count);
                int NL = raiseToPower(2, count - 1) - LAT;
                if (NL > 98) {
                    for (int v = 0; v < 15; ++v) {
                        srand(tempSbox[v] * (curIter * v) % 256);
                        int coeff = rand() % 256;
                        printf("coeff1 %d", coeff);
                        int coeff2 = rand() % 256;
                        printf("coeff2 %d", coeff2);
                        int temp = tempSbox[coeff];
                        tempSbox[coeff] = tempSbox[coeff2];
                        tempSbox[coeff2] = temp;
                    }
                }
            }
            for (int k = 0; k < size; ++k) {
                population[N + i][k] = tempSbox[k];
                //printf("%d ", tempSbox[k]);
            }
            //printf("\n");
        }
        /*printf("\nNEW Arrays\n");
        for (int q = 0; q < 2*N; ++q){
            for(int w = 0; w < size; ++w){
                printf("%d, ",population[q][w]);
            }
            int LAT = LATMax(population[q],size,count);
            int NL = raiseToPower(2, count - 1) - LAT;
            printf( "\nNon-linearity from LAT = %d \n", NL);
            printf("\n");
            printf("\n\n");
        }*/
        int arrNL2[2 * N];
        for (int q = 0; q < 2 * N; ++q) {
            for (int w = 0; w < size; ++w) {
                printf("%d ", population[q][w]);
            }
            int LAT = LATMax(population[q], size, count);
            int NL = raiseToPower(2, count - 1) - LAT;
            printf("\nNon-linearity from LAT = %d \n", NL);
            printf("\n");
            arrNL2[q] = NL;
        }
        int g2[size];
        for (int i = 0; i < 2 * N; ++i) {
            for (int j = (2 * N - 1); j > i; --j) {
                if (arrNL2[j] > arrNL2[j - 1]) {
                    int h = arrNL2[j - 1];
                    arrNL2[j - 1] = arrNL2[j];
                    arrNL2[j] = h;
                    for (int k = 0; k < size; ++k) {
                        g2[k] = population[j - 1][k];
                        population[j - 1][k] = population[j][k];
                        population[j][k] = g2[k];
                    }
                }
            }
        }
        printf("\n");
        for (int q = 0; q < 2 * N; ++q) {
            printf("\n%d ", arrNL2[q]);
        }
        for (int q = N; q < 2 * N; ++q) {
            for (int w = 0; w < size; ++w) {
                population[q][w] = 0;
            }
        }
        printf("\nSORTED BY Non-Linearity\n");
        for (int q = 0; q < N; ++q) {
            for (int w = 0; w < size; ++w) {
                printf("%d, ", population[q][w]);
            }
            printf("\n\n");
        }
        if (curIter == 0) {
            for (int m = 0; m < size; ++m) {
                gBest[m] = population[0][m];
            }
            for (int i = 1; i < N; ++i) {
                for (int j = 0; j < size; ++j) {
                    pBest[i - 1][j] = population[i][j];
                }
            }
        }
        else {
            for (int m = 0; m < size; ++m) {
                gBest[m] = population[1][m];
            }
            for (int i = 2; i < N; ++i) {
                for (int j = 0; j < size; ++j) {
                    pBest[i - 1][j] = population[i][j];
                }
            }
        }
        printf("\n\n");
        printf("\ngBest\n");
        for (int m = 0; m < size; ++m){
            printf("%d, ",gBest[m]);
        }
        printf("\npBest\n");
        for (int q = 0; q < N-1; ++q){
            for(int w = 0; w < size; ++w){
                printf("%d, ",pBest[q][w]);
            }
            printf("\n\n");
        }
        for (int h = 1; h < N; ++h){
            int LAT3 = LATMax(population[h], size, count);
            int NL3 = raiseToPower(2, count - 1) - LAT3;
            printf("\nNon-linearity from LAT = %d \n", NL3);
            printf("\n");
            int sp3[255][256];
            int ac3[255][256];
            int ucCheck3 = linearRedundancy(population[h], 256, 8, sp3, ac3);
            int ai3 = algebraicImmunity(population[h],256,8);
            int du3 = deltaUniformity(population[h],256,8);
            printf( "\n\nImmunity   = %d \n", ai3);
            printf("\nDelta-Uniformity  = %d \n", du3);
            int lr;
            if (ucCheck3 == 1) {
                printf("\nLinear redundancy = %d \n", (256) - ucCheck3);
                lr = 256-ucCheck3;
            } else {
                printf("\nLinear redundancy = %d \n", (256 - 1) - ucCheck3);
                lr = (256 - 1) - ucCheck3;
            }
            if (NL3 >= 104 && ai3 == 3 && lr == 0){
                printf("current iter = %d ",curIter+1);
                *finalIter = curIter+1;
                maxIter = -99;
                break;
            }
            if (flag102 == 0 && NL3 == 102 && ai3 == 3 && lr == 0){
                FILE *fileLocal;
                fopen_s(&fileLocal, "Table results N, MaxIter, IterToFind, Time.txt", "a");
                if (fileLocal == NULL) {
                    printf("ERROR: Can't save sbox to file!\n");
                    for (;;);
                }
                clock_t finish = clock();
                double a = (double) (finish - start) / CLOCKS_PER_SEC;
                fprintf(fileLocal, "\n%d       %d       %d              %d        %d,%d", NL3,N,500,curIter+1,(int)a,(int)((-1)*(floor(a)-a)*1000000));
                printf("current iter = %d ",curIter+1);
                fclose(fileLocal);
                flag102 = 1;
            }
        }
        maxIter = maxIter-1;
        mode = 0;
        ++curIter;
    }
    //printf("\n\nFinal data\n\n");
    int *result = calloc(N*size, sizeof(int));
    //printf("final current iter = %d ",*finalIter);
    for (int q = 0; q < N; ++q) {
        for (int w = 0; w < size; ++w) {
            result[q * size + w] = population[q][w];
            //printf("%d, ", result[q * size + w]);
        }
        //printf("\n\n");
    }
    return result;
}

//Перемішування Фішера-Йейтсаq

void FisherYates(int *arr, int n) {
    int i, j, tmp;

    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        tmp = arr[j];
        arr[j] = arr[i];
        arr[i] = tmp;
    }
}

//Функція бульбашкового сортування за спаданням

void bubblesortDescending(int *data, int size) {
    int i, j;
    for (i = 0; i < size; ++i) {
        for (j = size - 1; j > i; --j) {
            if (data[j] > data[j-1]) {
                int t = data[j - 1];
                data[j - 1] = data[j];
                data[j] = t;
            }
        }
    }
}

int *CombFromWHTMatrix(int *func, int size, int count){
    int *result = calloc (size,sizeof(int));
    for (int i = 0; i < size; ++i) {
        result[i] = func[i];
    }
    for (int i = 0; i < size; ++i){
        printf("%d, ", result[i]);
    }
    printf("\n");
    int ac2 = 0;
    int nl2 = 0;
    int deg = 0;
    int one = 0;
    int zer = 0;
    int newNl = 0;
    int counter = 0;
    while (1) {
        for (int i = 0; i < size; ++i){
            printf("%d, ", result[i]);
        }
        srand(time(NULL));
        int flag = rand();
        ++counter;
        srand((counter*flag)%1000);
        for (int i = 0; i < size; ++i) {
            if (result[i] == 1) {
                ++one;
            } else if (result[i] == 0) {
                ++zer;
            }
        }
        /*for (int i = 0; i < size; ++i){
            printf("%d, ", result[i]);
        }*/
        printf("\n");
        int *fxarr = HadamardCoefficients(result, size, count);
        printf("\nHADAMARD COEFFICIENTS");
        printf("\n");
        for (int i = 0; i < size; ++i) {
            printf("%d ", fxarr[i]);
        }
        int max1 = HadamardMax(fxarr, size);
        //printf("\n max = %d", max1);
        nl2 = HadamardNLinearity(max1, count);
        printf("\n");
        printf("\nHADAMARD NON LINEARITY = %d", nl2);
        printf("\n");

        printf("\n");
        printf("\n");
        int *ac = autoCorrelation(result, size, count);
        for (int i = 0; i < size; ++i) {
            printf("%d ", ac[i]);
        }
        ac2 = autoCorrelationMax(ac, size);
        printf("\n");
        printf("\nAUTO CORRELATION  = %d", ac2);
        printf("\n");

        deg = algebraicDeg(result, size, count);
        printf("\n");
        printf("\nDEG  = %d", deg);

        printf("\n");
        printf("\nN  = %d", count);
        printf("\n");
        printf("\nNON ZERO  = %d", one);
        printf("\n");
        printf("\nZERO  = %d", zer);
        if (ac2 == 8 && nl2 == 26 && deg == 5 && one==zer){
            printf("\nRES\n");
            for (int i = 0; i < size; ++i){
                printf("%d, ", result[i]);
            }
            break;
        }
        int coeff = rand()%64;
        int coeff2 = (rand()+rand())%64;
        //int coeff3 = (rand()+rand()+rand())%64;
        //int coeff4 = (rand()+rand()+rand()+rand())%64;
        printf("\n coeff = %d", coeff);
        printf("\n coeff2 = %d", coeff2);
        //printf("\n coeff3 = %d", coeff3);
        //printf("\n coeff4 = %d", coeff4);
        if (one > zer) {
            if (result[coeff] == 1) {
                result[coeff] = 0;
            }
            if (result[coeff2] == 1) {
                result[coeff2] = 0;
            }
                /*if (result[coeff3] == 1) {
                    result[coeff3] = 0;
                }
                if (result[coeff4] == 1) {
                    result[coeff4] = 0;
                }*/
            else {
            }
        }
        else {
            if (result[coeff] == 0) {
                result[coeff] = 1;
            }
            if (result[coeff2] == 0) {
                result[coeff2] = 1;
            }
                /*if (result[coeff3] == 1) {
                    result[coeff3] = 0;
                }
                if (result[coeff4] == 1) {
                    result[coeff4] = 0;
                }*/
            else {
            }
        }
        one = 0;
        zer = 0;
        free(fxarr);
        free(ac);
    }
    return result;
}

int *CombFromWHTGoodComb(int *func, int size, int count){
    int *result = calloc (size,sizeof(int));
    for (int i = 0; i < size; ++i) {
        result[i] = func[i];
    }
    for (int i = 0; i < size; ++i){
        printf("%d, ", result[i]);
    }
    printf("\n");
    int ac2 = 0;
    int nl2 = 0;
    int deg = 0;
    int one = 0;
    int zer = 0;
    int newNl = 0;
    int counter = 0;
    while (1) {
        for (int i = 0; i < size; ++i){
            printf("%d, ", result[i]);
        }
        srand(time(NULL));
        int flag = rand();
        ++counter;
        srand((counter*flag)%1000);
        for (int i = 0; i < size; ++i) {
            if (result[i] == 1) {
                ++one;
            } else if (result[i] == 0) {
                ++zer;
            }
        }
        /*for (int i = 0; i < size; ++i){
            printf("%d, ", result[i]);
        }*/
        printf("\n");
        int *fxarr = HadamardCoefficients(result, size, count);
        printf("\nHADAMARD COEFFICIENTS");
        printf("\n");
        for (int i = 0; i < size; ++i) {
            printf("%d ", fxarr[i]);
        }
        int max1 = HadamardMax(fxarr, size);
        //printf("\n max = %d", max1);
        nl2 = HadamardNLinearity(max1, count);
        printf("\n");
        printf("\nHADAMARD NON LINEARITY = %d", nl2);
        printf("\n");

        printf("\n");
        printf("\n");
        int *ac = autoCorrelation(result, size, count);
        for (int i = 0; i < size; ++i) {
            printf("%d ", ac[i]);
        }
        ac2 = autoCorrelationMax(ac, size);
        printf("\n");
        printf("\nAUTO CORRELATION  = %d", ac2);
        printf("\n");

        deg = algebraicDeg(result, size, count);
        printf("\n");
        printf("\nDEG  = %d", deg);

        printf("\n");
        printf("\nN  = %d", count);
        printf("\n");
        printf("\nNON ZERO  = %d", one);
        printf("\n");
        printf("\nZERO  = %d", zer);
        if (ac2 == 8 && nl2 == 26 && deg == 5 && one==zer){
            printf("\nRES\n");
            for (int i = 0; i < size; ++i){
                printf("%d, ", result[i]);
            }
            break;
        }
        int *NewRes = calloc (size,sizeof(int));
        for (int i = 0; i < size; ++i){
            NewRes[i] = result[i];
        }
        int coeff = rand()%64;
        int coeff2 = (rand()+rand())%64;
        //int coeff3 = (rand()+rand()+rand())%64;
        //int coeff4 = (rand()+rand()+rand()+rand())%64;
        printf("\n coeff = %d", coeff);
        printf("\n coeff2 = %d", coeff2);
        //printf("\n coeff3 = %d", coeff3);
        //printf("\n coeff4 = %d", coeff4);
        if (result[coeff] == 1 && result[coeff2] == 0) {
            NewRes[coeff] = 0;
            NewRes[coeff2] = 1;
        }
        else if (result[coeff] == 0 && result[coeff2] == 1) {
            NewRes[coeff] = 1;
            NewRes[coeff2] = 0;
        }

        int *fxarr2 = HadamardCoefficients(NewRes, size, count);
        int max2 = HadamardMax(fxarr2, size);
        //printf("\n max = %d", max1);
        int nl3 = HadamardNLinearity(max2, count);
        printf("\n");
        printf("\nHADAMARD NON LINEARITY = %d", nl3);
        printf("\n");

        printf("\n");
        printf("\n");
        int *acMs = autoCorrelation(NewRes, size, count);
        int ac3 = autoCorrelationMax(acMs, size);
        printf("\n");
        printf("\nAUTO CORRELATION  = %d", ac3);
        printf("\nNEWRES\n");
        for (int i = 0; i < size; ++i){
            printf("%d, ", NewRes[i]);
        }
        printf("\n");
        printf("\n");
        if (nl3 >= nl2 && ac3 <=ac2){
            for (int i = 0; i < size; ++i){
                result[i] = NewRes[i];
            }
        }
        else{

        }
        /*if (result[coeff2] == 1) {
            result[coeff2] = 0;
        }*/
        /*if (result[coeff3] == 1) {
            result[coeff3] = 0;
        }
        if (result[coeff4] == 1) {
            result[coeff4] = 0;
        }*/
        /*if (result[coeff2] == 0) {
            result[coeff2] = 1;
        }*/
        /*if (result[coeff3] == 1) {
            result[coeff3] = 0;
        }
        if (result[coeff4] == 1) {
            result[coeff4] = 0;
        }*/
        one = 0;
        zer = 0;
        free(fxarr);
        free(ac);
        free(NewRes);
        free(fxarr2);
        free(acMs);
    }
    return result;
}

void sortComb (int *s, int N)
{
    int i,j;
    int buf;

    for ( i=0;i<N;i++)
        for ( j=N-1;j>i;j--)
            if (s[j]<s[j-1])
            {
                buf=s[j];
                s[j]=s[j-1];
                s[j-1]=buf;
            }

}

int *sortAndFind(int *func, int size, int count){
    int buf;
    int i,j,N,k,q;
    printf("\nVuvesti vse perestanovki\nVvedite stroku s: ");
    N=size;
    printf ("\nDlina stroki N=%d", N);
    printf("\nVse vozmozhnuye perestenovki: ");

    sortComb(func, N);

    while (1) {
        printf("\n");
        printf("\n");
        printf("\n");
        for (int m = 0; m < size; ++m) {
            printf("%d, ", func[m]);
        }
        printf("\n");

        int one = 0,zer = 0;

        for (int i = 0; i < size; ++i) {
            if (func[i] == 1) {
                ++one;
            } else if (func[i] == 0) {
                ++zer;
            }
        }

        int *fxarr = HadamardCoefficients(func, size, count);
        //printf("\nHADAMARD COEFFICIENTS");
        //printf("\n");
        /*for (int i = 0; i < size; ++i) {
            printf("%d ", fxarr[i]);
        }*/
        int max1 = HadamardMax(fxarr, size);
        //printf("\n max = %d", max1);
        int nl2 = HadamardNLinearity(max1, count);
        printf("\nHADAMARD NON LINEARITY = %d", nl2);

        //printf("\n");
        //printf("\n");
        int *ac = autoCorrelation(func, size, count);
        /*for (int i = 0; i < size; ++i) {
            printf("%d ", ac[i]);
        }*/
        int ac2 = autoCorrelationMax(ac, size);
        printf("\nAUTO CORRELATION  = %d", ac2);

        int deg = algebraicDeg(func, size, count);
        printf("\nDEG  = %d", deg);

        printf("\nN  = %d", count);
        printf("\nNON ZERO  = %d", one);
        printf("\nZERO  = %d", zer);
        if (ac2 == 8 && nl2 == 26 && deg == 5 && one==zer){
            printf("\nRES\n");
            for (int i = 0; i < size; ++i){
                printf("%d, ", func[i]);
            }
            return func;
            break;
        }


        for (i = N-2; i >= 0  && func[i] >= func[i+1] ; i--);
        if (i<0) break;
        for(j=N-1; func[i] >= func[j]; j--) ;
        buf = func[j];
        func[j] = func[i];
        func[i] = buf;

        for ( k=i+1, q=N-1; k < q; k++ , q-- )
        {   buf=func[k];
            func[k]=func[q];
            func[q]=buf;
        }
        one = 0;
        zer = 0;
        free(fxarr);
        free(ac);
    }
    printf("\n");
    return NULL;
}





