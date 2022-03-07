#include <string>
#include <memory>
#include "elements.h"
#include "render.h"

std::string HtmlElement::Render() {
    std::string returnString;
    returnString.append(GenerateTabs(nested_depth));
    returnString.append("<");
    returnString.append(tagname);

    unsigned int attributesLength = attributes.size();
    for (int i = 0; i < attributesLength; i++) {
        HtmlAttribute attribute = attributes[i];
        returnString.append(" " + attribute.key + "=\"" + attribute.value + "\"");
    }

    returnString.append(">\n");

    unsigned int childsLength = childs.size();
    for (int i = 0; i < childsLength; i++) {
        std::shared_ptr<Renderable> renderable = childs[i];
        returnString.append(renderable->Render());
    }

    returnString.append(GenerateTabs(nested_depth));
    returnString.append("</" + tagname + ">\n");

    return returnString;
}
