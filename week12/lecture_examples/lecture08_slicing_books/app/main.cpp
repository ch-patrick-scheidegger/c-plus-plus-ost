#include <iostream>
#include <vector>

using Page=int;

struct Book {
  explicit Book(std::vector<Page> pages) :
    pages{pages}{}
  virtual Page currentPage() const = 0;
  Page lastPage() const { return pages.size();}
protected:
  std::vector<Page> pages;
};

struct EBook : Book {
  using Book::Book;
  void openPage(size_t pageNumber);
  Page currentPage() const;
private:
  size_t currentPageNumber{1};
};

void readPage(Page);
std::vector<Page> writeEbook(int pages);


int main() {

  EBook designPatterns{writeEbook(395)};
  EBook refactoring{writeEbook(430)};
  refactoring.openPage(400);
  Book & some = refactoring;
  std::cout << "pages to read: "<< some.lastPage() << '\n';
  readPage(some.currentPage());
  some = designPatterns; // only base part copied over!
  std::cout << "pages to read: "<< some.lastPage() << '\n';
  readPage(some.currentPage());
}

std::vector<Page> writeEbook(int pages){
    return std::vector<Page>(pages);
}

void readPage(Page p){
    std::cout << "Page read:" << p << '\n';
}

void EBook::openPage(size_t pageNumber){
    this->currentPageNumber=pageNumber;
}
Page EBook::currentPage() const {
    return this->currentPageNumber;
}


