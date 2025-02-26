#pragma once
#include "scripting/script_environment.h"

namespace Halley {
	class ScriptWaitData : public IScriptStateData {
	public:
		float timeLeft = 0;

		ConfigNode toConfigNode(const ConfigNodeSerializationContext& context) override;
	};
	
	class ScriptWait final : public ScriptNodeTypeBase<ScriptWaitData> {
	public:
		String getId() const override { return "wait"; }
		String getName() const override { return "Wait for Time"; }
		String getIconName(const ScriptGraphNode& node) const override { return "script_icons/wait.png"; }
		gsl::span<const PinType> getPinConfiguration() const override;
		std::vector<SettingType> getSettingTypes() const override;
		std::pair<String, std::vector<ColourOverride>> getNodeDescription(const ScriptGraphNode& node, const World& world, const ScriptGraph& graph) const override;
		ScriptNodeClassification getClassification() const override { return ScriptNodeClassification::FlowControl; }
		Result doUpdate(ScriptEnvironment& environment, Time time, const ScriptGraphNode& node, ScriptWaitData& curData) const override;
		void doInitData(ScriptWaitData& data, const ScriptGraphNode& node, const ConfigNode& nodeData) const override;
	};
}
