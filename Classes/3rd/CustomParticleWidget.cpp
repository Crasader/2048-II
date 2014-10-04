//
//  CustomParticleWidget.cpp
//  CustomUI
//
//  Created by cai wenzhi on 14-3-7.
//
//

#include "CustomParticleWidget.h"

USING_NS_CC;
using namespace ui;

CustomParticleWidget::CustomParticleWidget()
: _emitter(NULL)
, _emitterPlist("")
{
    
}

CustomParticleWidget::~CustomParticleWidget()
{
    
}

CCObject* CustomParticleWidget::createInstance()
{
    return create();
}

CustomParticleWidget* CustomParticleWidget::create()
{
    CustomParticleWidget* custom = new CustomParticleWidget();
    
    if (custom && custom->init())
    {
        custom->autorelease();
        return custom;
    }
    CC_SAFE_DELETE(custom);
    return NULL;
}

bool CustomParticleWidget::init()
{
    if (Widget::init())
    {
        return true;
    }
    return false;
}

void CustomParticleWidget::initRenderer()
{
    Widget::initRenderer();
    
}

void CustomParticleWidget::removeAllChildren()
{
    CC_SAFE_RELEASE(_emitter);
    _emitter = NULL;
    Widget::removeAllChildren();
}

void CustomParticleWidget::setParticlePlist(const char *plist)
{
    if (_emitter)
    {
        _emitter->removeFromParent();
        CC_SAFE_RELEASE(_emitter);
        _emitter = NULL;
        this->initRenderer();
	}
	_emitter = ParticleSystemQuad::create(plist);
    _emitter->setPosition(0,0);
	_emitterPlist = plist;
	CCNode::addChild(_emitter , getZOrder() + 1, -1);
}

const char* CustomParticleWidget::getParticlePlist() const
{
    return _emitterPlist;
}

void CustomParticleWidget::setParticlePosition(const CCPoint &pos)
{
    _emitter->setPosition(pos);
    
    _emitterPostion = pos;
}

const CCPoint& CustomParticleWidget::getParticlePosition() const
{
    return _emitterPostion;
}

void CustomParticleWidget::playParticle()
{
    if (_emitter)
    {
        _emitter->resetSystem();
    }
    
}

void CustomParticleWidget::stopParticle()
{
    if (_emitter)
    {
        _emitter->stopSystem();
    }
    
}

Vector<Node *> & CustomParticleWidget::getChildren()
{
	return CCNode::getChildren();
}


