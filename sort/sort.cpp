#include <iostream>
#include<memory>
#include<fstream>
#include<time.h>
#include<limits>
#include <random>

template <class T>
void sort(std::unique_ptr<T[]>& arr, size_t nElements)
{
  if (nElements < 2) return;
  T maxNegElem = std::numeric_limits<T>::min();
  T minNegElem = 1;
  T maxPosElem = -1;
  T minPosElem = std::numeric_limits<T>::max();
  for (size_t i = 0; i < nElements; i++) {
    if (arr[i] > 0) {
      minPosElem = std::min(minPosElem, arr[i]);
      maxPosElem = std::max(maxPosElem, arr[i]);
    }
    else {
      minNegElem = std::min(minNegElem, arr[i]);
      maxNegElem = std::max(maxNegElem, arr[i]);
    }
  }
  if (minNegElem == maxPosElem) return;

  try {
    if (minNegElem <= 0 && maxPosElem < 0) {
      if (minNegElem == maxNegElem) return;
      //k >= 0
      // -4 -5 -6
      T helpingArrayLength = minNegElem * -1 + maxNegElem + 1;
      std::unique_ptr<T[]> countsOfNegElements(new T[helpingArrayLength]);
      for (size_t i = 0; i < helpingArrayLength; i++) {
        countsOfNegElements[i] = 0;
      }
      for (size_t i = 0; i < nElements; i++) {
        countsOfNegElements[arr[i] * -1 + maxNegElem]++;
      }
      int k = 0;
      for (int i = minNegElem - maxNegElem; i <= 0; i++) {
        for (int j = 0; j < countsOfNegElements[i * -1]; j++) {
          arr[k++] = i + maxNegElem;
        }
      }
    }
    else if (minNegElem <= 0 && maxPosElem >= 0) {
      T helpingNegArrayLength = minNegElem * -1 + maxNegElem + 1;
      //4 5 6
      T helpingPosArrayLength = maxPosElem - minPosElem + 1;
      std::unique_ptr<T[]> countsOfNegElements(new T[helpingNegArrayLength]);
      std::unique_ptr<T[]> countsOfPosElements(new T[helpingPosArrayLength]);
      for (int i = 0; i < helpingNegArrayLength; i++) {
        countsOfNegElements[i] = 0;
      }
      for (int i = 0; i < helpingPosArrayLength; i++) {
        countsOfPosElements[i] = 0;
      }
      for (size_t i = 0; i < nElements; i++) {
        if (arr[i] <= 0) {
          countsOfNegElements[arr[i] * -1 + maxNegElem]++;
        }
        else {
          countsOfPosElements[arr[i] - minPosElem]++;
        }
      }
      int k = 0;
      //negative partь
      for (int i = minNegElem - maxNegElem; i <= 0; i++) {
        for (int j = 0; j < countsOfNegElements[i * -1]; j++) {
          arr[k++] = i + maxNegElem;
        }
      }
      //positive part =)
      for (int i = 0; i < maxPosElem - minPosElem + 1; i++) {
        for (int j = 0; j < countsOfPosElements[i]; j++) {
          arr[k++] = i + minPosElem;
        }
      }
    }
    else {
      if (minPosElem == maxPosElem) return;
      T helpingPosArrayLength = maxPosElem - minPosElem + 1;
      std::unique_ptr<T[]> countsOfPosElements(new T[helpingPosArrayLength]);
      for (int i = 0; i < helpingPosArrayLength; i++) {
        countsOfPosElements[i] = 0;
      }
      for (size_t i = 0; i < nElements; i++) {
        countsOfPosElements[arr[i] - minPosElem]++;
      }
      int k = 0;
      for (int i = 0; i < maxPosElem - minPosElem + 1; i++) {
        for (int j = 0; j < countsOfPosElements[i]; j++) {
          arr[k++] = i + minPosElem;
        }
      }
    }
  }
  catch (std::bad_alloc) {
    std::cerr << "Ran out of memory!\n";
    throw std::bad_alloc();
  }
}

int main()
{
  std::ifstream input("testFile.txt");
  if (!input.is_open()) {
    std::cerr << "ERROR: The file wasnt open!";
    return -1;
  }
  int nNumbers(0);
  input >> nNumbers;
  std::unique_ptr<int[]> arr(new int[nNumbers]);
  for (int i = 0; i < nNumbers; i++) {
    input >> arr[i];
  }
  std::cout << "\n";
  sort(arr, nNumbers);
  for (int i = 0; i < nNumbers; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout.precision(10);
  std::cout << '\n' << (double)(end-start);
  input.close();
}
