#include "script_play_animation.h"

#include "halley/core/graphics/sprite/animation_player.h"
#ifndef DONT_INCLUDE_HALLEY_HPP
#define DONT_INCLUDE_HALLEY_HPP
#endif
#include "world.h"
#include "components/sprite_animation_component.h"

using namespace Halley;

std::vector<IScriptNodeType::SettingType> ScriptPlayAnimation::getSettingTypes() const
{
	return { SettingType{ "sequence", "Halley::String", std::vector<String>{"default"} } };
}

gsl::span<const IScriptNodeType::PinType> ScriptPlayAnimation::getPinConfiguration() const
{
	using ET = ScriptNodeElementType;
	using PD = ScriptNodePinDirection;
	const static auto data = std::array<PinType, 3>{ PinType{ ET::FlowPin, PD::Input }, PinType{ ET::FlowPin, PD::Output }, PinType{ ET::TargetPin, PD::Output } };
	return data;
}

std::pair<String, std::vector<ColourOverride>> ScriptPlayAnimation::getNodeDescription(const ScriptGraphNode& node, const World& world, const ScriptGraph& graph) const
{
	ColourStringBuilder str;
	str.append("Play sequence \"");
	str.append(node.getSettings()["sequence"].asString("default"), Colour4f(0.97f, 0.35f, 0.35f));
	str.append("\" on entity \"");
	str.append(node.getTargetName(world, 2), Colour4f(0.97f, 0.35f, 0.35f));
	str.append("\".");
	return str.moveResults();
}

IScriptNodeType::Result ScriptPlayAnimation::doUpdate(ScriptEnvironment& environment, Time time, const ScriptGraphNode& node) const
{
	auto entity = environment.tryGetEntity(node.getPin(2).entity);
	if (entity.isValid()) {
		auto* spriteAnimation = entity.tryGetComponent<SpriteAnimationComponent>();
		if (spriteAnimation) {
			spriteAnimation->player.setSequence(node.getSettings()["sequence"].asString(""));
		}
	}
	return Result(ScriptNodeExecutionState::Done);
}
