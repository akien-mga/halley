#pragma once
#include "scripting/script_environment.h"

namespace Halley {
	class ScriptVariable final : public ScriptNodeTypeBase<void> {
	public:
		String getId() const override { return "variable"; }
		String getName() const override { return "Variable"; }
		String getIconName(const ScriptGraphNode& node) const override { return "script_icons/variable.png"; }
		gsl::span<const PinType> getPinConfiguration() const override;
		std::vector<SettingType> getSettingTypes() const override;
		ScriptNodeClassification getClassification() const override { return ScriptNodeClassification::Variable; }
		std::pair<String, std::vector<ColourOverride>> getNodeDescription(const ScriptGraphNode& node, const World& world, const ScriptGraph& graph) const override;

		ConfigNode doGetData(ScriptEnvironment& environment, const ScriptGraphNode& node, size_t pinN) const override;
	};
	
	class ScriptLiteral final : public ScriptNodeTypeBase<void> {
	public:
		String getId() const override { return "literal"; }
		String getName() const override { return "Literal"; }
		String getIconName(const ScriptGraphNode& node) const override { return "script_icons/literal.png"; }
		gsl::span<const PinType> getPinConfiguration() const override;
		std::vector<SettingType> getSettingTypes() const override;
		ScriptNodeClassification getClassification() const override { return ScriptNodeClassification::Variable; }
		std::pair<String, std::vector<ColourOverride>> getNodeDescription(const ScriptGraphNode& node, const World& world, const ScriptGraph& graph) const override;

		ConfigNode doGetData(ScriptEnvironment& environment, const ScriptGraphNode& node, size_t pinN) const override;
	};
	
	class ScriptComparison final : public ScriptNodeTypeBase<void> {
	public:
		String getId() const override { return "comparison"; }
		String getName() const override { return "Comparison"; }
		String getIconName(const ScriptGraphNode& node) const override { return "script_icons/comparison.png"; }
		gsl::span<const PinType> getPinConfiguration() const override;
		std::vector<SettingType> getSettingTypes() const override;
		ScriptNodeClassification getClassification() const override { return ScriptNodeClassification::Variable; }
		std::pair<String, std::vector<ColourOverride>> getNodeDescription(const ScriptGraphNode& node, const World& world, const ScriptGraph& graph) const override;

		ConfigNode doGetData(ScriptEnvironment& environment, const ScriptGraphNode& node, size_t pinN) const override;
	};
	
	class ScriptSetVariable final : public ScriptNodeTypeBase<void> {
	public:
		String getId() const override { return "setVariable"; }
		String getName() const override { return "Set Variable"; }
		String getIconName(const ScriptGraphNode& node) const override { return "script_icons/set_variable.png"; }
		gsl::span<const PinType> getPinConfiguration() const override;
		ScriptNodeClassification getClassification() const override { return ScriptNodeClassification::Action; }
		std::pair<String, std::vector<ColourOverride>> getNodeDescription(const ScriptGraphNode& node, const World& world, const ScriptGraph& graph) const override;

		Result doUpdate(ScriptEnvironment& environment, Time time, const ScriptGraphNode& node) const override;
	};
	
}
