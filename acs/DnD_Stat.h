#ifndef DND_EXP_IN
#define DND_EXP_IN

#include "DnD_Quests.h"
#include "DnD_CommonStat.h"
#include "DnD_Common.h"
#include "DnD_Charms.h"

#define DND_HARDCORE_DROPRATEBONUS 0.15

#define BASE_WISDOM_GAIN 10
#define BASE_GREED_GAIN 10

enum {
	DND_ANNOUNCER_QUEST,
	DND_ANNOUNCER_ATTRIBPOINT,
	DND_ANNOUNCER_LEGENDARYMONSTER,
	DND_ANNOUNCER_RESEARCHDISCOVER,
	DND_ANNOUNCER_TRADEREQUEST
};

// RPG ELEMENTS
int LevelCurve[MAXLEVELS + 1] = { 100, 264, 480, 696, 912, 1128, 1340, 1560, 1780, 1990, 2210, 2420, 2640, 2860, 4200, 5800, 6100, 6600, 6900, 8350, 9900, 10300, 10900, 11400, 11800, 12300, 12800, 13300, 13800, 14300, 19000, 22700, 27000, 31900, 37900, 45000, 53300, 63000, 75000, 89000, 105000, 125000, 149000, 175000, 209000, 247000, 294000, 348000, 412000, 490000, 579000, 680000, 820000, 970000, 1150000, 1360000, 1610000, 1920000, 2270000, 2690000, 3200000, 3780000, 4490000, 5260000, 6300000, 7500000, 8900000, 10600000, 12500000, 14800000, 17500000, 20900000, 24700000, 29300000, 34800000, 41200000, 48900000, 57200000, 69000000, 82000000, 96000000, 115000000, 136000000, 161000000, 192000000, 227000000, 269000000, 319000000, 378000000, 449000000, 528000000, 630000000, 750000000, 890000000, 1050000000, 1250000000, 1480000000, 1750000000, 2090000000, 2147483647, 2147483647 };

global bool 9: PlayerWillBeSaved[MAXPLAYERS];
global bool 10: PlayerTransferred[MAXPLAYERS];

int GetExpLimit() {
	return LevelCurve[GetStat(STAT_LVL) - 1];
}

str TalentNames[MAX_TALENTS] = {
	"Talent_Ballistic",
	"Talent_Melee",
	"Talent_Occult",
	"Talent_Explosive",
	"Talent_Energy",
    "Talent_Elemental"
};

str TalentTypeNames[MAX_TALENTS] = {
	"Ballistic",
	"Melee",
	"Occult",
	"Explosive",
	"Energy",
    "Elemental"
};

#define DND_PERKS DND_PERK_END - DND_PERK_BEGIN + 1
str StatLabels[STAT_LVLCRED + 1] = {
	"Strength",
	"Dexterity",
	"Bulkiness",
	"Charisma",
	"Vitality",
	"Intellect",
	
	"Sharpshooting",
	"Endurance",
	"Wisdom",
	"Greed",
	"Medic",
	"Munitionist",
	"Deadliness",
	"Savagery",
	"Luck",
	
	"Experience",
	"Level Experience",
	"Level",
	"Credit",
	"Level Credit"
};

str StatNames[STAT_LVLCRED + 1] = {
	"PSTAT_Strength",
	"PSTAT_Dexterity",
	"PSTAT_Bulkiness",
	"PSTAT_Charisma",
	"PSTAT_Vitality",
	"PSTAT_Intellect",
	
	"Perk_Sharpshooting",
	"Perk_Endurance",
	"Perk_Wisdom",
	"Perk_Greed",
	"Perk_Medic",
	"Perk_Munitionist",
    "Perk_Deadliness",
	"Perk_Savagery",
	"Perk_Luck",
	
	"Exp",
	"LevelExp",
	"Level",
	"Credit",
	"LevelCredit"
};

enum {
	DND_ARMOR_BONUS,
	DND_ARMOR_GREEN,
	DND_ARMOR_YELLOW,
	DND_ARMOR_BLUE,
	DND_ARMOR_RED,
	
	DND_ARMOR_GUNSLINGER,
	DND_ARMOR_OCCULT,
	DND_ARMOR_DEMO,
	DND_ARMOR_ENERGY,
	DND_ARMOR_ELEMENTAL,
	
	DND_ARMOR_SUPER,
	DND_ARMOR_CYBERNETIC,
	DND_ARMOR_DUELIST,
	DND_ARMOR_NECRO,
	DND_ARMOR_KNIGHT,
	DND_ARMOR_RAVAGER
};
#define MAXARMORS DND_ARMOR_RAVAGER + 1

str ArmorTypes[MAXARMORS] = {
	"ArmorBonus",
	"NewGreenArmor",
	"YellowArmor",
	"NewBlueArmor",
	"TheRedArmor",
	
	"GunSlingerArmor",
	"OccultArmor",
	"DemoArmor",
	"EnergyArmor",
	"ElementalArmor",
	
	"SuperArmor",
	"CyberneticArmor",
	"DuelistArmor",
	"NecroArmor",
	"KnightArmor",
	"RavagerArmor"
};

int ArmorBaseAmounts[MAXARMORS] = {
	1,
	100,
	150,
	200,
	300,
	
	200,
	200,
	200,
	200,
	200,
	
	400,
	300,
	250,
	400,
	400,
	250
};

enum {
	DND_CKEY_BRONZE,
	DND_CKEY_SILVER,
	DND_CKEY_GOLD
};

#define MAX_CHEST_KEYS DND_CKEY_GOLD + 1
str ChestKeyTypes[MAX_CHEST_KEYS] = {
	"BronzeChestKey",
	"SilverChestKey",
	"GoldChestKey"
};

int GetStat(int stat_id) {
	return CheckInventory(StatNames[stat_id]);
}

int GetActorStat(int tid, int stat_id) {
	return CheckActorInventory(tid, StatNames[stat_id]);
}

void GiveStat(int stat_id, int amt) {
	SetInventory(StatNames[stat_id], Clamp_Between(CheckInventory(StatNames[stat_id]) + amt, 0, DND_STAT_FULLMAX));
}

void GiveActorStat(int tid, int stat_id, int amt) {
	SetActorInventory(tid, StatNames[stat_id], Clamp_Between(CheckActorInventory(tid, StatNames[stat_id]) + amt, 0, DND_STAT_FULLMAX));
}

void GiveExp(int amt) {
	GiveInventory("Exp", amt);
	GiveInventory("ExpVisual", amt);
	GiveInventory("SpreeXP", amt);
	GiveInventory("LevelExp", amt);
}

void GiveActorExp(int tid, int amt) {
	GiveActorInventory(tid, "Exp", amt);
	GiveActorInventory(tid, "ExpVisual", amt);
	GiveActorInventory(tid, "SpreeXP", amt);
	GiveActorInventory(tid, "LevelExp", amt);
}

void GiveCredit(int amt) {
	GiveInventory("Credit", amt);
	GiveInventory("LevelCredit", amt);
}

void GiveBudget(int amt) {
	GiveInventory("Budget", amt);
}

void GiveActorCredit(int tid, int amt) {
	GiveActorInventory(tid, "Credit", amt);
	GiveActorInventory(tid, "LevelCredit", amt);
}

int GetDexterity() {
	int res = CheckInventory("PSTAT_Dexterity");
	if(CheckInventory("DnD_QuestReward_TalentIncrease"))
		res = res * (100 + DND_QUEST_TALENTBONUS) / 100;
	return res;
}

int GetIntellect() {
	int res = CheckInventory("PSTAT_Intellect");
	if(CheckInventory("DnD_QuestReward_TalentIncrease"))
		res = res * (100 + DND_QUEST_TALENTBONUS) / 100;
	return res;
}

int GetStrength() {
	return CheckInventory("PSTAT_Strength");
}

void CleanSharpEndPerks(int flags) {
	int i;
	// Take previous perk stuff
	if(flags & RES_PERK_SHARP && CheckInventory("Perk_SharpShooting") > 1) {
		for(i = 0; i < DND_PERK_MAX; ++i)
			TakeInventory(StrParam(s:"Damage_Perk_", d:(i + 1) * 5), 1);
	}
	if(flags & RES_PERK_ENDURANCE && CheckInventory("Perk_Endurance") > 1) {
		for(i = 0; i < DND_PERK_MAX; ++i)
			TakeInventory(StrParam(s:"Resist_Perk_", d:(i + 1) * 5), 1);
	}
}

void UpdateSharpEndPerks(int flags) {
	if((flags & RES_PERK_SHARP) && CheckInventory("Perk_Sharpshooting"))
		GiveInventory(StrParam(s:"Damage_Perk_", d:CheckInventory("Perk_Sharpshooting") * SHARPSHOOTING_DAMAGE), 1);
	if((flags & RES_PERK_ENDURANCE) && CheckInventory("Perk_Endurance"))
		GiveInventory(StrParam(s:"Resist_Perk_", d:CheckInventory("Perk_Endurance") * ENDURANCE_RESIST), 1);
}

bool ReachedAccessoryLimit() {
	// consider accessory limit enhancement here
	int baselimit = DND_ACCESSORY_BASELIMIT;
	int cur = CheckInventory("Accessory_Index");
	int count = 0;
	// counts bits of 1
	while(cur && count < baselimit) {
		if(cur & 1)
			++count;
		cur >>= 1;
	}
	return count >= baselimit;
}

void EquipAccessory(int acc) {
	SetInventory("Accessory_Index", CheckInventory("Accessory_Index") | acc);
	DecideAccessories();
}

void UnequipAccessory(int acc) {
	SetInventory("Accessory_Index", CheckInventory("Accessory_Index") & ~acc);
	DecideAccessories();
}

int CalculateArmorCapBonuses() {
	int res = CheckInventory("DnD_QuestReward_ArmorCapIncrease") * DND_QUEST_ARMORBONUS;
	
	// consider orb effects
	res += GetDataFromOrbBonus(PlayerNumber(), OBI_ARMORFLAT, -1);
	
	return res;
}

// used for displaying to hud
int GetArmorCap(bool useMenuShow) {
	// see if this DND_BASE_ARMOR_SHOW breaks anything -- breaks armor shards
	int res = CalculateArmorCapBonuses() + DND_ARMOR_PER_BUL * CheckInventory("PSTAT_Bulkiness");
	if(useMenuShow)
		res += DND_BASE_ARMOR_SHOW;
	else
		res += DND_BASE_ARMOR;
	res += res * (GetDataFromOrbBonus(PlayerNumber(), OBI_ARMORPERCENT, -1) + DND_TORRASQUE_BOOST * CheckInventory("DnD_QuestReward_TorrasqueBonus")) / 100;
	res += (res * CheckInventory("PSTAT_Strength") * DND_STR_CAPINCREASE) / DND_STR_CAPFACTOR;
	res += (res * CheckInventory("CelestialCheck") * CELESTIAL_BOOST) / 100;
	res += (res * GetResearchArmorBonuses()) / 100;
	res += (res * Player_Bonuses[PlayerNumber()].armor_percent_bonus) / 100;
	return res;
}

// used for deciding armor pickup values
int GetArmorSpecificCap(int amt) {
	if(amt != 1) { 
		// any other armor besides the armor bonuses
		amt += CalculateArmorCapBonuses() + DND_ARMOR_PER_BUL * CheckInventory("PSTAT_Bulkiness");
		amt += amt * (GetDataFromOrbBonus(PlayerNumber(), OBI_ARMORPERCENT, -1) + DND_TORRASQUE_BOOST * CheckInventory("DnD_QuestReward_TorrasqueBonus")) / 100;
		amt += (amt * CheckInventory("PSTAT_Strength") * DND_STR_CAPINCREASE) / DND_STR_CAPFACTOR;
		amt += (amt * CheckInventory("CelestialCheck") * CELESTIAL_BOOST) / 100;
		amt += (amt * GetResearchArmorBonuses()) / 100;
		amt += (amt * Player_Bonuses[PlayerNumber()].armor_percent_bonus) / 100;
	}
	else // exception for armor bonus
		amt = GetArmorCap(false) >> 1;
	return amt;
}

// compare armor types t1 and t2, check if t1 is of higher tier than t2
// if base armor of item greater and it is listed greater
int IsArmorTierHigher(int t1, int t2) {
	return ArmorBaseAmounts[t1] > ArmorBaseAmounts[t2] && t1 > t2;
}

void HandleArmorPickup(int armor_type, int amount, bool replace) {
	int armor = CheckInventory("Armor"), cap = 0;
	GiveInventory("DnD_BoughtArmor", 1);
	if(armor_type == DND_ARMOR_BONUS) {
		// if we had no armor
		if(!armor) {
			SetInventory("DnD_ArmorType", armor_type + 1);
			cap = GetArmorCap(false) >> 1;
		}
		else {
			cap = GetArmorSpecificCap(ArmorBaseAmounts[CheckInventory("DnD_ArmorType") - 1]);
		}
		// just add 1 to current armor if meets requirements
		amount = (amount * cap) / 100;
		// allow it to fill up to x3 of the armor cap
		cap *= 3;
		if(armor + amount < cap) {
			GiveInventory("DnD_ArmorBonus", amount);
			GiveInventory("Research_Body_Ar_1_Tracker", amount);
		}
		else {
			GiveInventory("DnD_ArmorBonus", cap - armor);
			GiveInventory("Research_Body_Ar_1_Tracker", cap - armor);
		}
	}
	else {
		// only give the actual armor if my tier is higher!
		if(IsArmorTierHigher(armor_type, CheckInventory("DnD_ArmorType") - 1) || replace) {
			// gross hacks
			SetInventory("Armor", 0);
			GiveInventory(ArmorTypes[armor_type], 1);
			// prevent armor downgrades
			GiveInventory("DnD_ArmorBonus", armor - 1);
			SetInventory("DnD_ArmorType", armor_type + 1);
		}
		
		/*if(armor) // if we had armor, retain it
			GiveInventory("DnD_ArmorBonus", armor - 1);*/
			
		armor = CheckInventory("Armor");
		// respect the cap of the currently equipped armor
		cap = GetArmorSpecificCap(ArmorBaseAmounts[CheckInventory("DnD_ArmorType") - 1]);
		// set armor count
		if(armor + amount > cap) {
			GiveInventory("DnD_ArmorBonus", cap - armor);
			GiveInventory("Research_Body_Ar_1_Tracker", cap - armor);
		}
		else {
			GiveInventory("DnD_ArmorBonus", amount);
			GiveInventory("Research_Body_Ar_1_Tracker", amount);
		}
	}
	
	HandleArmorDependencyCheck();
}

int Calculate_Stats() {
	int res = 0;
	for(int i = DND_ATTRIB_BEGIN; i <= DND_ATTRIB_END; ++i)
		res += CheckInventory(StatNames[i]);
	return res;
}

int Calculate_Perks() {
	int res = 0;
	for(int i = DND_PERK_BEGIN; i <= DND_PERK_END; ++i)
		res += CheckInventory(StatNames[i]);
	return res;
}

int GetDropChance(int pnum, bool isElite) {
	int base = 1.0; // base val
	base += Player_Bonuses[pnum].drop_chance + GetDataFromOrbBonus(pnum, OBI_DROPCHANCE, -1); // additive bonuses first
	if(isElite && CheckActorInventory(pnum + P_TIDSTART, "DnD_QuestReward_EliteDropBonus"))
		base += DND_ELITEDROP_GAIN;
	// luck benefits are multiplicative
	base = FixedMul(base, 1.0 + DND_LUCK_GAIN * CheckActorInventory(pnum + P_TIDSTART, "Perk_Luck") + Player_Bonuses[pnum].luck);
	if(GetCVar("dnd_hardcore"))
		base = FixedMul(base, 1.0 + DND_HARDCORE_DROPRATEBONUS);
	return base;
}

int GetPlayerWisdomBonus(int pnum) {
	return Player_Bonuses[pnum].wisdom_percent_bonus + GetDataFromOrbBonus(pnum, OBI_WISDOMPERCENT, -1);
}

int GetPlayerGreedBonus(int pnum) {
	return Player_Bonuses[pnum].greed_percent_bonus + GetDataFromOrbBonus(pnum, OBI_GREEDPERCENT, -1);
}

bool RunDefaultDropChance(int pnum, bool isElite, int basechance) {
	return RunDropChance(pnum, isElite, basechance, 0, 1.0);
}

bool RunDropChance(int pnum, bool isElite, int basechance, int low, int high) {
	return FixedMul(GetDropChance(pnum, isElite), basechance) >= random(low, high);
}

void DecideAccessories() {
	int this = ActivatorTID();
	if(IsAccessoryEquipped(this, DND_ACCESSORY_AMULETHELLFIRE)) {
		GiveInventory("Accessory_FireProtection", 1);
		GiveInventory("HellfireCheck", 1);
	}
	else {
		TakeInventory("Accessory_FireProtection", 1);
		TakeInventory("HellfireCheck", 1);
	}
		
	if(IsAccessoryEquipped(this, DND_ACCESSORY_ANGELICANKH)) {
		if(!CheckInventory("Intervened")) {
			SetPlayerProperty(0, 1, PROP_BUDDHA);
			GiveInventory("CanIntervene", 1);
		}
	}
	else {
		SetPlayerProperty(0, 0, PROP_BUDDHA);
		TakeInventory("CanIntervene", 1);
	}
	
	if(IsAccessoryEquipped(this, DND_ACCESSORY_DEMONBANE)) {
		GiveInventory("DemonBaneCheck", 1);
		GiveInventory("DemonBaneReduction", 1);
	}
	else {
		TakeInventory("DemonBaneReduction", 1);
		TakeInventory("DemonBaneCheck", 1);
	}
	
	if(IsAccessoryEquipped(this, DND_ACCESSORY_PENDANTREFLECTION))
		GiveInventory("CanDeflect", 1);
	else
		TakeInventory("CanDeflect", 1);
		
	if(IsAccessoryEquipped(this, DND_ACCESSORY_NETHERMASK)) {
		GiveInventory("NetherCheck", 1);
		GiveInventory("NetherWeaken", 1);
	}
	else {
		TakeInventory("NetherCheck", 1);
		TakeInventory("NetherWeaken", 1);
	}
		
	if(IsAccessoryEquipped(this, DND_ACCESSORY_TALTOSRING)) {
		GiveInventory("TaltosEffect", 1);
		GiveInventory("TaltosUp", 1);
	}
	else {
		GiveInventory("TaltosUnsetEffect", 1);
		TakeInventory("TaltosUp", 1);
	}
	
	if(IsAccessoryEquipped(this, DND_ACCESSORY_HATESHARD)) {
		GiveInventory("HateCheck", 1);
		GiveInventory("PowerReflection", 1);
		GiveInventory("HateReduction", 1);
	}
	else {
		TakeInventory("PowerReflection", 1);
		TakeInventory("HateCheck", 1);
		TakeInventory("HateReduction", 1);
	}
	
	if(IsAccessoryEquipped(this, DND_ACCESSORY_HANDARTEMIS)) {
		GiveInventory("ArtemisPower", 1);
		GiveInventory("ArtemisCheck", 1);
		GiveInventory("ArtemisReduction", 1);
	}
	else {
		TakeInventory("ArtemisPower", 1);
		TakeInventory("ArtemisCheck", 1);
		TakeInventory("ArtemisReduction", 1);
	}
	
	if(IsAccessoryEquipped(this, DND_ACCESSORY_AGAMOTTO))
		GiveInventory("AgamottoCheck", 1);
	else
		TakeInventory("AgamottoCheck", 1);
	
	if(IsAccessoryEquipped(this, DND_ACCESSORY_GRYPHONBOOTS)) {
		GiveInventory("CurseImmunity", 1);
		GiveInventory("GryphonCheck", 1);
		GiveInventory("GryphonSpeed", 1);
		UpdatePlayerKnockbackResist();
	}
	else {
		TakeInventory("CurseImmunity", 1);
		TakeInventory("GryphonCheck", 1);
		TakeInventory("GryphonSpeed", 1);
	}
	
	if(IsAccessoryEquipped(this, DND_ACCESSORY_LICHARM)) {
		GiveInventory("LichCheck", 1);
		GiveInventory("LichPower", 1);
		SetAmmoCapacity("Souls", 150);
	}
	else {
		TakeInventory("LichCheck", 1);
		TakeInventory("LichPower", 1);
		if(CheckInventory("Souls") > 75) // yea this is bad but o well
			SetInventory("Souls", 75);
		SetAmmoCapacity("Souls", 75);
	}
	
	// sigil order: 1 = fire, 2 = ice, 3 = lightning, 4 = poison
	if(IsAccessoryEquipped(this, DND_ACCESSORY_SIGILELEMENTS))
		SetInventory("SigilCheck", 1);
	else {
		SetInventory("SigilCheck", 0);
		TakeInventory("ElementPower_Fire", 1);
		TakeInventory("ElementPower_Ice", 1);
		TakeInventory("ElementPower_Lightning", 1);
		TakeInventory("ElementPower_Earth", 1);
	}
	if(IsAccessoryEquipped(this, DND_ACCESSORY_CELESTIAL)) {
		SetInventory("CelestialCheck", 1);
		GiveInventory("CelestialSlow", 1);
	}
	else {
		SetInventory("CelestialCheck", 0);
		TakeInventory("CelestialSlow", 1);
	}
	
	SetInventory("HunterTalismanCheck", IsAccessoryEquipped(this, DND_ACCESSORY_HUNTERTALISMAN));
	SetInventory("VeilCheck", IsAccessoryEquipped(this, DND_ACCESSORY_VEIL));
}

bool HasNoSigilPower() {
	return !CheckInventory("ElementPower_Fire") && !CheckInventory("ElementPower_Ice") && !CheckInventory("ElementPower_Lightning") && !CheckInventory("ElementPower_Earth");
}

// Takes a stat from the player, also removing effects of it
void TakeStat(int stat_id, int amt) {
	TakeInventory(StatNames[stat_id], amt);
}

void UpdatePerkStuff() {
	CleanSharpEndPerks(RES_PERK_SHARP | RES_PERK_ENDURANCE);
	RestoreRPGStat(RES_PERK_SHARP | RES_PERK_ENDURANCE);
	SetAmmoCapacity("StoredMedkit", GetAmmoCapacity("StoredMedkit") + 15 * CheckInventory("Perk_Medic"));
}

void UpdatePlayerKnockbackResist() {
	int bul = CheckInventory("PSTAT_Bulkiness");
	int strgth = CheckInventory("PSTAT_Strength");
	
	if(IsAccessoryEquipped(0, DND_ACCESSORY_GRYPHONBOOTS))
		SetActorProperty(0, APROP_MASS, INT_MAX);
	else
		SetActorProperty(0, APROP_MASS, DND_BASE_PLAYER_MASS + bul * DND_BUL_KNOCKBACK_GAIN + strgth * DND_STR_KNOCKBACK_GAIN + Player_Bonuses[PlayerNumber()].knockback_resist);
}

bool HasKilledLegendary(int id) {
	return IsSet(CheckInventory("LegendaryKills"), id);
}

void UpdateLegendaryKill(int pnum, int mon_id) {
	SetActorInventory(pnum + P_TIDSTART, "LegendaryKills", CheckActorInventory(pnum + P_TIDSTART, "LegendaryKills") | (1 << mon_id));
}

int GetPlayerWeaponEnchant(int pnum, int wepid) {
	return GetDataFromOrbBonus(pnum, OBI_WEAPON_ENCHANT, wepid) + Player_Weapon_Infos[pnum][wepid].enchants;
}

void HandleArmorDependencyCheck() {
	// Research Dependency
	if(CheckInventory("Research_Body_Ar_1_Tracker") == GetAmmoCapacity("Research_Body_Ar_1_Tracker") && CheckResearchStatus(RES_EXO1) == RES_NA)
		GiveResearch(RES_EXO1, true);

	// check for thick skin quest
	if(active_quest_id == QUEST_NOARMORS && !CheckInventory(Quest_Checkers[active_quest_id])) {
		GiveInventory(Quest_Checkers[active_quest_id], 1);
		FailQuest(ActivatorTID(), active_quest_id);
	}
}

// break all trades between this player and others
void BreakTradesBetween(int pnum) {
	int i;
	int tid;
	// check all trades of all players, clean players who have one going with this guy
	for(int j = 0; j < MAXPLAYERS; ++j) {
		if(PlayerInGame(j)) {
			tid = j + P_TIDSTART;
			if(pnum > 31) {
				if(IsSet(CheckActorInventory(tid, "DnD_TradeEngaged_2"), pnum - 32)) 
					SetActorInventory(tid, "DnD_TradeEngaged_2", ClearBit(CheckActorInventory(tid, "DnD_TradeEngaged_2"), pnum - 32));
			}
			else if(IsSet(CheckActorInventory(tid, "DnD_TradeEngaged_1"), pnum)) 
				SetActorInventory(tid, "DnD_TradeEngaged_1", ClearBit(CheckActorInventory(tid, "DnD_TradeEngaged_1"), pnum));
		}
	}
}

void BreakAllTrades() {
	int tid;
	for(int j = 0; j < MAXPLAYERS; ++j) {
		if(PlayerInGame(j)) {
			tid = j + P_TIDSTART;
			SetActorInventory(tid, "DnD_TradeEngaged_1", 0);
			SetActorInventory(tid, "DnD_TradeEngaged_2", 0);
			TakeActorInventory(tid, "DnD_TradeAcceptWindow", 1);
		}
	}
}

int CheckDeadlinessCrit() {
	return CheckInventory("Perk_Deadliness") * PERK_DEADLINESS_BONUS;
}

bool CheckCritChance() {
	// veil disables crits for the cooldown period
	if(CheckInventory("VeilCheck") && CheckInventory("VeilCooldown"))
		return 0;
	bool res = 0;
	int chance = CheckDeadlinessCrit(), pnum = PlayerNumber(), wepid = GetWeaponPosFromTable();
	// add current weapon crit bonuses
	chance += Player_Weapon_Infos[pnum][wepid].wep_bonuses[WEP_BONUS_CRIT].amt;
	chance += GetDataFromOrbBonus(pnum, OBI_WEAPON_CRIT, wepid);
	chance += (Player_Bonuses[pnum].crit_chance << 16) / 100;
	// add percent bonus
	if(chance) {
		chance = FixedMul(chance, 1.0 + Player_Weapon_Infos[pnum][wepid].wep_bonuses[WEP_BONUS_CRITPERCENT].amt 
									  + GetDataFromOrbBonus(pnum, OBI_WEAPON_CRITPERCENT 
									  + (Player_Bonuses[pnum].crit_percent << 16) / 100, wepid));
	}
	
	res = chance >= random(0, 1.0);
	
	if(res && CheckInventory("VeilCheck") && !CheckInventory("VeilCooldown") && !CheckInventory("VeilMarkTimer")) {
		GiveInventory("VeilMarkTimer", 1);
		ActivatorSound("VeilOfAssassin/Active", 97);
	}
	
	return chance >= random(0, 1.0);
}

int GetCritModifier() {
	int base = DND_BASE_CRITMODIFIER; // 200, which is x2 more damage
	int bonus = DND_SAVAGERY_BONUS * CheckInventory("Perk_Savagery"), pnum = PlayerNumber(), wepid = GetWeaponPosFromTable();
	// weapon bonus
	bonus += Player_Weapon_Infos[pnum][wepid].wep_bonuses[WEP_BONUS_CRITDMG].amt >> 16;
	bonus += GetDataFromOrbBonus(pnum, OBI_WEAPON_CRITDMG, wepid) >> 16;
	bonus += Player_Bonuses[pnum].crit_damage;
	base += bonus;
	if(CheckInventory("HunterTalismanCheck"))
		base >>= 1;
	if(CheckInventory("VeilMarkTimer")) {
		if(!CheckInventory("VeilNextAttack"))
			GiveInventory("VeilNextAttack", 1);
		else {
			base <<= 1;
			TakeInventory("VeilMarkTimer", 1);
			TakeInventory("VeilNextAttack", 1);
			GiveInventory("VeilCooldown", 1);
			GiveInventory("VeilHealFXSpawner", 1);
			ACS_NamedExecuteAlways("DnD Health Pickup", 0, (DND_VEIL_FACTORUP * GetMissingHealth()) / DND_VEIL_FACTOR);
		}
	}
	return base;
}

void RecalculateTotalLevel() {
	total_level = 0;
	for(int i = 0; i < MAXPLAYERS; ++i) {
		if(PlayerInGame(i) && IsActorAlive(i + P_TIDSTART))
			total_level += CheckActorInventory(i + P_TIDSTART, "Level");
	}
}

void ResetPlayerBonuses(int pnum) {	
	int i;
	Player_Bonuses[pnum].hp_flat_bonus = 0;
	Player_Bonuses[pnum].armor_flat_bonus = 0;
	
	Player_Bonuses[pnum].hp_percent_bonus = 0;
	Player_Bonuses[pnum].armor_percent_bonus = 0;
	
	Player_Bonuses[pnum].greed_percent_bonus = 0;
	Player_Bonuses[pnum].wisdom_percent_bonus = 0;
	
	Player_Bonuses[pnum].speed_bonus = 0;
	Player_Bonuses[pnum].drop_chance = 0;
	Player_Bonuses[pnum].holding = 0;
	Player_Bonuses[pnum].luck = 0;
	
	for(i = 0; i < MAX_TALENTS; ++i)
		Player_Bonuses[pnum].damage_type_bonus[i] = 0;
		
	for(i = 0; i < MAX_TALENTS; ++i)
		Player_Bonuses[pnum].flat_damage_bonus[i] = 0;
		
	for(i = 0; i < MAX_WEAPON_SLOTS; ++i)
		Player_Bonuses[pnum].slot_damage_bonus[i] = 0;
	
	Player_Bonuses[pnum].magazine_increase = 0;
	Player_Bonuses[pnum].pellet_increase = 0;
	Player_Bonuses[pnum].explosion_radius = 0;
	Player_Bonuses[pnum].explosion_resist = 0;
	Player_Bonuses[pnum].ammo_chance = 0;
	Player_Bonuses[pnum].ammo_gain = 0;
	Player_Bonuses[pnum].regen_cap = 0;
	Player_Bonuses[pnum].crit_chance = 0;
	Player_Bonuses[pnum].crit_percent = 0;
	Player_Bonuses[pnum].crit_damage = 0;
	
	Player_Bonuses[pnum].knockback_resist = 0;
	Player_Bonuses[pnum].damage_percent = 0;
	Player_Bonuses[pnum].accuracy = 0;
}

void ResetHardcoreStuff(int pnum) {
	// reset player items
	ResetPlayerInventory(pnum);
	ResetPlayerCharmsUsed(pnum);
	ResetTradeViewList(pnum);
	ResetPlayerStash(pnum);
	// reset weapon mod variable
	ResetWeaponMods(pnum);
	ResetPlayerBonuses(pnum);
	ResetMostRecentOrb(pnum);
	ResetOrbData(pnum);
	RecalculateTotalLevel();
	BreakTradesBetween(pnum);
	// may join later, sync everything
	if(PlayerIsSpectator(pnum)) {
		SyncAllClientsideVariables();
		SyncAllItemData(DND_SYNC_ITEMSOURCE_CHARMUSED);
		SyncAllItemData(DND_SYNC_ITEMSOURCE_PLAYERINVENTORY);
		SyncAllItemData(DND_SYNC_ITEMSOURCE_STASH);
	}
}

#endif