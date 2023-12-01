#ifndef ECCommand_h
#define ECCommand_h
#include <vector>
#include <stack>
class ECTextDocument;

class ECCommand {
public:
    virtual ~ECCommand() = default;
    virtual void Execute() = 0;
    virtual void UnExecute() = 0;
};

// Implement command history

class ECCommandHistory {
public:
    ECCommandHistory();
    virtual ~ECCommandHistory();
    bool Undo();
    bool Redo();
    void AddCommand(ECCommand* pCmd){undoStack.push(pCmd);};
    void ExecuteCmd(ECCommand* pCmd);

private:
    std::stack<ECCommand*> undoStack;
    std::stack<ECCommand*> redoStack;
};

// Implement InsertCommand, RemoveCommand, CapCommand, LowerCommand

class InsertCommand : public ECCommand {
public:
    InsertCommand(ECTextDocument& doc, int pos, const std::vector<char>& listCharsToIns);
    void Execute() override;
    void UnExecute() override;

private:
    ECTextDocument* pDocument;
    int position;
    std::vector<char> insertedChars;
};

// Similar declarations for RemoveCommand, CapCommand, and LowerCommand

#endif