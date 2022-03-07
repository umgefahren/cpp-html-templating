#pragma once
#include "render.h"
#include <string>
#include <vector>
#include <memory>


class HtmlAttribute {
    public:
    std::string key;
    std::string value;

    HtmlAttribute(std::string key, std::string value) {
        HtmlAttribute::key = key;
        HtmlAttribute::value = value;
    }
    ~HtmlAttribute() {}
};

class HtmlElement : public Renderable {
    protected:
    std::string tagname;
    std::vector<HtmlAttribute> attributes;
    std::vector<std::shared_ptr<Renderable>> childs;

    public:

    HtmlElement(std::string tagName) : Renderable() {
        tagname = tagName;
    };

    ~HtmlElement() {};

    void addAttribute(HtmlAttribute attribute) {
        attributes.push_back(attribute);
    };

    void addChild(std::shared_ptr<Renderable> child) {
        child.get()->nested_depth += 1;
        childs.push_back(child);
    };

    virtual std::string Render();
};

class HtmlDocument : public Renderable {
    protected:
    std::vector<std::shared_ptr<Renderable>> body_childs;
    std::string title;

    HtmlDocument(std::string title) : Renderable() {
        HtmlDocument::title = title;
        nested_depth = 0;
    };

    ~HtmlDocument() {};

    void addChild(std::shared_ptr<Renderable> child) {
        child.get()->nested_depth += 1;
        body_childs.push_back(child);
    };

    virtual std::string Render();
};