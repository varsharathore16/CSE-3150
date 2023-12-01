// ECTextDocument.cpp

#include "ECTextDocument.h"
#include <iostream>
#include <cctype>

// Implementation of ECTextDocumentCtrl

ECTextDocumentCtrl::ECTextDocumentCtrl(ECTextDocument& docIn) : docCtrlHistory(), document(docIn) {
    // Initialize any necessary data members
      doc = &docIn;
      history = docCtrlHistory();
}

ECTextDocumentCtrl::~ECTextDocumentCtrl() {
    // Cleanup any resources if necessary
}

void ECTextDocumentCtrl::InsertTextAt(int pos, const std::vector<char>& listCharsToIns) {
    // Create an instance of InsertCommand and execute it
    InsertCommand* pCmd = new InsertCommand(document, pos, listCharsToIns);
    docCtrlHistory.ExecuteCmd(pCmd);
    history.AddCommand(pCmd);
    insert->Execute();
}

// Implement similar methods for RemoveTextAt, CapTextAt, LowerTextAt, Undo, and Redo
void ECTextDocumentCtrl :: RemoveTextAt(int pos, int lenToRemove)
{
  // your code
  ECRemoveCommand *remove = new ECRemoveCommand(doc, pos, lenToRemove);
  history.AddCommand(remove);
  remove->Execute();

}

// Implementation of ECTextDocument

ECTextDocument::ECTextDocument() {
    // Initialize any necessary data members
}

ECTextDocument::~ECTextDocument() {
    // Cleanup any resources if necessary
}

ECTextDocumentCtrl& ECTextDocument::GetCtrl() {
    return docCtrl;
}

char ECTextDocument::GetCharAt(int pos) const {
    // Implement the retrieval of a character at a given position
    if (pos >= 0 && pos < listChars.size()) {
        return listChars[pos];
    }
    return '\0'; // Return a null character for out-of-bounds access
}

void ECTextDocument::InsertCharAt(int pos, const std::vector<char>& charsToInsert) {
    // Implement the insertion of characters at a given position
    if (pos >= 0 && pos <= listChars.size()) {
        listChars.insert(listChars.begin() + pos, charsToInsert.begin(), charsToInsert.end());
    }
}

void ECTextDocument::RemoveCharAt(int pos, int lenToRemove) {
    // Implement the removal of characters at a given position
    if (pos >= 0 && pos + lenToRemove <= listChars.size()) {
        listChars.erase(listChars.begin() + pos, listChars.begin() + pos + lenToRemove);
    }
}

// Implement similar methods for CapCharAt and LowerCharAt
