#include "Editor.h"
#include <msclr\marshal_cppstd.h> // For string conversion


// Implement the handlers
void FlowchartStudio::Editor::Flowchart_MouseDown(Object^ sender, MouseEventArgs^ e) {
    if (e->Button == System::Windows::Forms::MouseButtons::Left) {
        isDragging = true;
        lastMousePosition = e->Location;
    }
}

void FlowchartStudio::Editor::Flowchart_MouseMove(Object^ sender, MouseEventArgs^ e) {
    if (isDragging) {
        // Calculate the offset
        System::Drawing::Point offset = System::Drawing::Point(e->X - lastMousePosition.X, e->Y - lastMousePosition.Y);

        // Update positions of all nodes
        for each (Node ^ node in nodes) {
            System::Drawing::Point newPosition = System::Drawing::Point(node->Position.X + offset.X, node->Position.Y + offset.Y);
            node->Position = newPosition;
        }

        lastMousePosition = e->Location;
        Flowchart->Invalidate(); // Redraw to update positions
    }
}

void FlowchartStudio::Editor::Flowchart_MouseUp(Object^ sender, MouseEventArgs^ e) {
    isDragging = false;
}

void FlowchartStudio::Editor::Flowchart_RightClick(Object^ sender, MouseEventArgs^ e) {
    // Event handler for right-click on Flowchart panel
    if (e->Button == System::Windows::Forms::MouseButtons::Right) {
        this->flowchartContextMenu->Show(this->Flowchart, e->Location);
    }
}


void FlowchartStudio::Editor::CreateFlowchartNodes() {
    String^ code = this->Preview->Text;
    nodes->Clear();
    std::string unmanagedCode = msclr::interop::marshal_as<std::string>(code);

    std::regex functionPattern(R"((\b[a-zA-Z_][a-zA-Z0-9_]*\b)\s+(\b[a-zA-Z_][a-zA-Z0-9_]*\b)\s*\(([^)]*)\)\s*\{)");
    std::regex forLoopPattern(R"(\bfor\s*\(([^)]+)\))");
    std::regex ifPattern(R"(\bif\s*\(([^)]+)\))");

    int depth = 0; // Initialize depth

    std::sregex_iterator functionsBegin(unmanagedCode.begin(), unmanagedCode.end(), functionPattern);
    std::sregex_iterator end;
    for (std::sregex_iterator i = functionsBegin; i != end; ++i) {
        std::smatch match = *i;
        AddFlowchartNode("Function: " + gcnew String(match[2].str().c_str()), depth);

        // Process the function body
        std::string functionBody = match.suffix().str();
        std::sregex_iterator forLoopsBegin(functionBody.begin(), functionBody.end(), forLoopPattern);
        depth++; // Increase depth for inner constructs
        for (std::sregex_iterator j = forLoopsBegin; j != end; ++j) {
            std::smatch loopMatch = *j;
            AddFlowchartNode("For Loop: " + gcnew String(loopMatch[1].str().c_str()), depth);
        }

        std::sregex_iterator ifBegin(functionBody.begin(), functionBody.end(), ifPattern);
        for (std::sregex_iterator k = ifBegin; k != end; ++k) {
            std::smatch ifMatch = *k;
            AddFlowchartNode("If Statement: " + gcnew String(ifMatch[1].str().c_str()), depth);
        }
        depth--; // Decrease depth after processing inner constructs
    }
}

void FlowchartStudio::Editor::AddFlowchartNode(String^ nodeText, int depth) {
    // Calculate position based on depth and node count
    int xPosition = 250 + (depth * 50); // Indent more for deeper levels
    int yPosition = 50 + 100 * nodes->Count;

    System::Drawing::Point position = System::Drawing::Point(xPosition, yPosition);
    Node^ newNode = gcnew Node(position, nodeText);
    nodes->Add(newNode);
    Flowchart->Invalidate();
}

void FlowchartStudio::Editor::Flowchart_Paint(Object^ sender, PaintEventArgs^ e) {
    Graphics^ g = e->Graphics;

    // Draw each node
    for each (Node ^ node in nodes) {
        node->Draw(g);
    }

    // Draw lines between nodes
    Node^ prevNode = nullptr;
    for each (Node ^ currentNode in nodes) {
        if (prevNode != nullptr) {
            Point start = Point(prevNode->Position.X + prevNode->Size.Width / 2, prevNode->Position.Y + prevNode->Size.Height);
            Point end = Point(currentNode->Position.X + currentNode->Size.Width / 2, currentNode->Position.Y);
            g->DrawLine(Pens::Black, start, end);
        }
        prevNode = currentNode;
    }
}


// Functional
void FlowchartStudio::Editor::AddNode_Click(Object^ sender, EventArgs^ e) {
    // Logic to add a new flowchart node at the cursor position
    System::Drawing::Point cursorPosition = this->Flowchart->PointToClient(System::Windows::Forms::Cursor::Position);
    int defaultDepth = 0; // Assuming default depth is 0
    AddFlowchartNode("New Node at " + cursorPosition.ToString(), defaultDepth);
}
