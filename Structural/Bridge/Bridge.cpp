/*
Bridge decouples an abstraction from its implementation allowing the two to vary independently.
https://en.wikipedia.org/wiki/Bridge_pattern
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Abstract Implementor
class IMedia {
public:
	virtual string title() = 0;
	virtual string url() = 0;
	virtual string image() = 0;
	virtual string description() = 0;
};
// Concrete Implementors
class AuthorMedia : public IMedia {
public:
	virtual string title() { return "Author Name"; } // in reality, calling Author->GetName
	virtual string url() { return "Author Facebook Link"; }
	virtual string image() { return "Author Photo";  }
	virtual string description() { return "Author Bio"; }
};
// Author and Book have different underlying objects having different methods
class BookMedia : public IMedia {
public:
	virtual string title() { return "Book Title"; } // in reality, calling Book->GetTitle, not GetName
	virtual string url() { return "Book Amazon Link"; }
	virtual string image() { return "Book Cover"; }
	virtual string description() { return "Book Abstract"; }
};

// Abstraction
class View {
protected:
	IMedia* media;
public:
	View(IMedia* media) : media(media) {}
	virtual string Show() = 0;
};

// Refined Abstractions
class LongView : public View {
public:
	LongView(IMedia* media) : View(media) {}
	virtual string Show() {
		return "Long View:\n" + media->title() + "\n" + media->url() + "\n" + media->image() + "\n" + media->description();
	}
};

class ShortView : public View {
public:
	ShortView(IMedia* media) : View(media) {}
	virtual string Show() {
		return "Short View:\n" + media->title() + "\n" + media->image();
	}
};

int main() {
	IMedia* book = new AuthorMedia();
	IMedia* author = new BookMedia();
	//now we can have all the possible combinations without implementing every possible combination
	View* AuthorLongView = new LongView(author);
	View* AuthorShortView = new ShortView(author);
	View* BookLongView = new LongView(book);
	View* BookShortView = new ShortView(book);
	
	cout << AuthorLongView->Show() << endl << endl;
	cout << AuthorShortView->Show() << endl << endl;
	cout << BookLongView->Show() << endl << endl;
	cout << BookShortView->Show() << endl << endl;

	system("pause");
	return 0;
}
