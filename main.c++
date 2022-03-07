#include <string>
#include <iostream>
#include <memory>
#include "render.h"
#include "elements.h"

int main() {

    HtmlElement internal = HtmlElement("h1");
    
    HtmlElement paragraph = HtmlElement("p");

    // std::shared_ptr<HtmlElement> shared = std::make_shared(paragraph);
    auto shared = std::make_shared<HtmlElement>(internal);

    paragraph.addChild(shared);
    
    std::string rendered = paragraph.Render();
    std::cout << rendered << std::endl;
    return 0;
}