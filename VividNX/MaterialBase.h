#pragma once
class MaterialBase
{
public:
	MaterialBase();
	~MaterialBase();
	virtual void Init();
	virtual void Bind();
	virtual void Release();
};

