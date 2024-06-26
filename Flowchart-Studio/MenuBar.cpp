#include "Editor.h"

/* MenuBar - Project  */
void FlowchartStudio::Editor::MenuBar_Project_ImportDirectory_Click(Object^ sender, EventArgs^ e) {
    if (this->FileExplorerDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        this->Hierarchy->Nodes->Clear();
        String^ path = this->FileExplorerDialog->SelectedPath;
        ListFiles(this->Hierarchy->Nodes, path);
    }
}
