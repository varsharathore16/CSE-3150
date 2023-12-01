// ECTextDocument.h

#ifndef ECTextDocument_h
#define ECTextDocument_h

#include "ECCommand.h"
#include <vector>

class ECTextDocumentCtrl;  // Forward declaration

class ECTextDocument {
public:
    ECTextDocument();
    virtual ~ECTextDocument();
    ECTextDocumentCtrl& GetCtrl();
    int GetDocLen() const { return listChars.size(); }
    char GetCharAt(int pos) const;
    void InsertCharAt(int pos, const std::vector<char>& charsToInsert);
    void RemoveCharAt(int pos, int lenToRemove);
    void CapCharAt(int pos, int lenToCap);
    void LowerCharAt(int pos, int lenToLower);
    // Declare other operations like RemoveTextAt, CapTextAt, LowerTextAt, etc.

private:
    std::vector<char> listChars;
    ECTextDocumentCtrl docCtrl; // Composition relationship with the controller
};

class ECTextDocumentCtrl {
public:
    ECTextDocumentCtrl(ECTextDocument& docIn);
    virtual ~ECTextDocumentCtrl();
    void InsertTextAt(int pos, const std::vector<char>& listCharsToIns);
    void RemoveTextAt(int pos, int lenToRemove);
    void CapTextAt(int pos, int lenToCap);
    void LowerTextAt(int pos, int lenToLower);
    bool Undo();
    bool Redo();

private:
    ECCommandHistory docCtrlHistory;
    ECTextDocument& document;
};

#endif /* ECTextDocument_h */
