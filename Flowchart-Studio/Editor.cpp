#include "Editor.h"



// Event handler for when SplitContainer2's splitter is moved
void FlowchartStudio::Editor::SplitContainer2_Update(Object^ sender, SplitterEventArgs^ e) {
    // Update the position of PreviewLabel relative to the splitter distance
    this->PreviewLabel->Location = System::Drawing::Point(this->splitContainer2->SplitterDistance, 40);

    // Recalculate FlowchartLabel's position
    SplitContainer_MoveLabel();
}

// Event handler for when the SplitContainer1's splitter is moved
void FlowchartStudio::Editor::SplitContainer1_Update(Object^ sender, SplitterEventArgs^ e) {
    // Recalculate FlowchartLabel's position
    SplitContainer_MoveLabel();
}

void FlowchartStudio::Editor::SplitContainer_MoveLabel() {
    // Calculate the center of the Flowchart panel
    int flowchartCenter = this->splitContainer2->SplitterDistance + (this->splitContainer1->SplitterDistance / 2);

    // Calculate the new X position for FlowchartLabel
    int newX = flowchartCenter - (this->FlowchartLabel->Width / 2);

    // Ensure the FlowchartLabel does not go past the right edge of SplitContainer2's Panel1
    int maxX = this->splitContainer2->SplitterDistance - (this->FlowchartLabel->Width / 2);
    if (newX > maxX) {
        newX = maxX;
    }

    // Ensure the FlowchartLabel does not go before the left edge of SplitContainer2's Panel2
    int minX = this->splitContainer2->SplitterDistance + (this->splitContainer1->Panel1->Width / 2);
    if (newX < minX) {
        newX = minX - 400;
    }

    // The Y position should remain constant as it is positioned above the Flowchart panel
    int newY = this->FlowchartLabel->Location.Y;

    // Update the position of FlowchartLabel
    this->FlowchartLabel->Location = System::Drawing::Point(newX, newY);
}






/* Import */







