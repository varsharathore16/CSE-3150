// ECCommand.cpp

#include "ECCommand.h"
#include "ECTextDocument.h"
#include <typeinfo>
#include <iostream>


// Implementation of ECCommandHistory

ECCommandHistory::ECCommandHistory() {
    // Initialize your command history data structure, e.g., vectors for undo and redo stacks
      undoStack = std::stack<ECCommand*>();
      redoStack = std::stack<ECCommand*>();
}

ECCommandHistory::~ECCommandHistory() {
    // Cleanup any resources if necessary
    
    while(!redoStack.empty()){
      ECCommand* top = redoStack.top();
      redoStack.pop();
      if(top != nullptr)
        delete top;
    }
    
    while(!undoStack.empty()){
      ECCommand* top = undoStack.top();
      undoStack.pop();
      if(top != nullptr)
        delete top;
    }
}

bool ECCommandHistory::Undo() {
    if (!undoStack.empty()) {
        ECCommand* cmd = undoStack.top();
        undoStack.pop();
        cmd->UnExecute();
        redoStack.push(cmd);  
        return true;
    }
    return false;
}

bool ECCommandHistory::Redo() {
    if (!redoStack.empty()) {
        ECCommand* cmd = redoStack.top();
        redoStack.pop();
        cmd->Execute();
        undoStack.push(cmd);
        return true;
    }
    return false;
}

void ECCommandHistory::ExecuteCmd(ECCommand* pCmd) {
    // Execute the command and store it in the command history for undo/redo
    pCmd->Execute();
    undoStack.push(pCmd);

    // Clear the redo stack when a new command is executed
    while (!redoStack.empty()) {
        delete redoStack.top();
        redoStack.pop();
    }
}

// Now, let's implement the concrete command classes for each operation (Insert, Remove, Cap, Lower) in ECCommand.cpp

// Implementation of InsertCommand

InsertCommand::InsertCommand(ECTextDocument& doc, int pos, const std::vector<char>& listCharsToIns)
    : pDocument(&doc), position(pos), insertedChars(listCharsToIns) {
}

void InsertCommand::Execute() {
    // Implement the insert functionality in the document
    pDocument->InsertCharAt(position, insertedChars);
}

void InsertCommand::UnExecute() {
    // Implement the reverse of insert to undo the operation
    pDocument->RemoveCharAt(position, insertedChars.size());
}

// Similar implementations for RemoveCommand, CapCommand, and LowerCommand

