#include "Editor.h"

void FlowchartStudio::Editor::ListFiles(TreeNodeCollection^ nodes, String^ path) {
    array<String^>^ entries = Directory::GetFileSystemEntries(path);
    for each (String ^ entry in entries) {
        TreeNode^ node = gcnew TreeNode(Path::GetFileName(entry));
        nodes->Add(node);
        if (Directory::Exists(entry)) {
            ListFiles(node->Nodes, entry);
        }
    }
}


/* Hierarchy - Project Tree*/
void FlowchartStudio::Editor::Hierarchy_Select(System::Object^ sender, TreeViewEventArgs^ e) {
    String^ fileExtension = Path::GetExtension(e->Node->FullPath);
    if (fileExtension == ".cpp" || fileExtension == ".h") {
        try {
            String^ currentDirectory = Directory::GetCurrentDirectory();
            String^ fullPath = Path::Combine(currentDirectory, e->Node->FullPath);
            this->Preview->Text = File::ReadAllText(fullPath);

            // Clear existing nodes and recreate them based on the new file
            nodes->Clear();
            CreateFlowchartNodes(); // Assuming this method will parse the new file and create nodes
            Flowchart->Invalidate(); // Redraw the flowchart panel to reflect the changes
        }
        catch (System::IO::IOException^ ex) {
            // Handle the exception
            this->Preview->Text = ex->Message;
        }
    }
    else {
        this->Preview->Text = "Not a supported file type.";
    }
}
