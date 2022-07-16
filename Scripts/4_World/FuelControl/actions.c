modded class ActionConstructor {

	override void RegisterActions(TTypenameArray actions) {
		super.RegisterActions(actions);
		actions.Insert(ActionFillAtStation);
		actions.Insert(ActionSiphon);
	}
};

modded class CarScript {
	override void SetActions() {
		super.SetActions();
		AddAction(ActionFillAtStation);
		AddAction(ActionSiphon);
	}
};

modded class ActionDrainLiquidCB : ActionContinuousBaseCB
{
	private const float TIME_TO_REPEAT = 0.25;
	
	override void CreateActionComponent()
	{
		
		FuelControlSettings settings = GetFuelControlSettings();
		float targetRate = settings.liquid_transfer_rates.Get(m_ActionData.m_Target.GetObject().GetType());
		if (!targetRate) {
			targetRate = UAQuantityConsumed.DRAIN_LIQUID;
		}
		float itemRate = settings.liquid_transfer_rates.Get(m_ActionData.m_MainItem.GetType());
		if (!itemRate) {
			itemRate = UAQuantityConsumed.DRAIN_LIQUID;
		}
		
		float transferRate;
		
		if (targetRate < itemRate) {
			transferRate = targetRate;
		} else {
			transferRate = itemRate;
		}
		
		m_ActionData.m_ActionComponent = new CAContinuousQuantityLiquidTransfer(transferRate, TIME_TO_REPEAT, true);
	}
};

modded class ActionPourLiquidCB : ActionContinuousBaseCB
{
	private const float TIME_TO_REPEAT = 0.25;
	
	override void CreateActionComponent()
	{
		FuelControlSettings settings = GetFuelControlSettings();
		float targetRate = settings.liquid_transfer_rates.Get(m_ActionData.m_Target.GetObject().GetType());
		if (!targetRate) {
			targetRate = UAQuantityConsumed.DRAIN_LIQUID;
		}
		float itemRate = settings.liquid_transfer_rates.Get(m_ActionData.m_MainItem.GetType());
		if (!itemRate) {
			itemRate = UAQuantityConsumed.DRAIN_LIQUID;
		}
		
		float transferRate;
		
		if (targetRate < itemRate) {
			transferRate = targetRate;
		} else {
			transferRate = itemRate;
		}

		m_ActionData.m_ActionComponent = new CAContinuousQuantityLiquidTransfer(transferRate, TIME_TO_REPEAT, false);
	}
};