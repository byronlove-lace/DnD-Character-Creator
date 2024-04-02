#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <random>

using std::string;
using std::vector;
using std::array;
using std::cout;
using std::endl;
using std::unordered_map;

class Entity
{
        private:
                string title;
                string desc;

        public:
                // Constructor
                Entity(string title, string desc)
                        :   title(title), desc(desc) {}

                Entity(string title)
                        :   title(title), desc("Blank") {}

                Entity()
                        :   title("Blank"), desc("Blank") {}

                // Getters
                const string getTitle() const
                {
                        return title;
                }

                const string getDesc() const
                {
                        return desc;
                }

                // Setters
                void setTitle(const string& newTitle)
                {
                        title = newTitle;
                }

                void setDesc(const string& newDesc)
                {
                        desc = newDesc;
                }
};

class Proficiencies
{
        private:
                unordered_map<string, bool> proficiencyRegistry;

        public:
                // Constructor
                Proficiencies(unordered_map<string, bool> registry)
                        :   proficiencyRegistry(registry) {}

                // Setters
                virtual void setProficiency(const string& name, const bool value)
                {
                        if (proficiencyRegistry.find(name) != proficiencyRegistry.end())
                        {
                                proficiencyRegistry[name] = value;
                        }
                        else 
                                throw std::invalid_argument("Invalid Proficiency.");
                }

                // Getters
                virtual bool getProficiency(const string& name) 
                {
                        if (proficiencyRegistry.find(name) != proficiencyRegistry.end())
                        {
                                return proficiencyRegistry[name];
                        }
                        else 
                                throw std::invalid_argument("Invalid Proficiency.");
                }
};

class AttributeProficiencies : public Proficiencies
{
        public:
                AttributeProficiencies()
                        : Proficiencies({
                        {"Strength", false},
                        {"Dexterity", false},
                        {"Constitution", false},
                        {"Intelligence", false},
                        {"Wisdom", false},
                        {"Charisma", false} 
                        }) {}

                // Methods
                const string convertAttribute(string name) 
                {
                        if (name == "STR") {
                                name = "Strength";
                        } else if (name == "DEX") {
                                name = "Dexterity";
                        } else if (name == "CON") {
                                name = "Constitution";
                        } else if (name == "INT") {
                                name = "Intelligence";
                        } else if (name == "WIS") {
                                name = "Wisdom";
                        } else if (name == "CHA") {
                                name = "Charisma";
                        }

                        return name;
                }

                // Setters
                void setProficiency(const string& name, const bool value) override
                {
                        string fullName = convertAttribute(name);
                        Proficiencies::setProficiency(fullName, value);
                }

                // Getters
                bool getProficiency(const string& name) override
                {
                        string fullName = convertAttribute(name);
                        return Proficiencies::getProficiency(fullName);
                }
};

class ToolProficiencies : public Proficiencies
{
        public:
                ToolProficiencies()
                        :  Proficiencies({
                        {"Alchemist Supplies", false},
                        {"Brewer's Supplies", false},
                        {"Calligrapher's Supplies", false},
                        {"Carpenter's Tools", false},
                        {"Cartographer's Tools", false},
                        {"Cobbler's Tools", false},
                        {"Cook's Utensils", false},
                        {"Glassblower's Tools", false},
                        {"Jeweler's Tools", false},
                        {"Leatherworker's Tools", false},
                        {"Mason's Tools", false},
                        {"Painter's Supplies", false},
                        {"Potter's Tools", false},
                        {"Smith's Tools", false},
                        {"Tinker's Tools", false},
                        {"Weaver's Tools", false},
                        {"Woodcarver's Tools", false},
                        {"Dice Set", false},
                        {"Dragonchess Set", false},
                        {"Playing Card Set", false},
                        {"Three Dragon Ante Set", false},
                        {"Bagpipes", false},
                        {"Drum", false},
                        {"Dulcimer", false},
                        {"Flute", false},
                        {"Lute", false},
                        {"Lyre", false},
                        {"Horn", false},
                        {"Pan Flute", false},
                        {"Shawm", false},
                        {"Viol", false},
                        {"Disguise Kit", false},
                        {"Forgery Kit", false},
                        {"Herbalism Kit", false},
                        {"Navigator's Tools", false},
                        {"Poisoner's Kit", false},
                        {"Thieves' Tools", false}
                }) {}
};

class ClassSkillProficiencies : public Proficiencies
{
        private:       
                unsigned int choiceNum;

        public:
                // Constructors
                ClassSkillProficiencies(unsigned int choiceNum)
                        : Proficiencies({
                                        {"Acrobatics", false},
                                        {"Animal Handling", false},
                                        {"Arcana", false},
                                        {"Athletics", false},
                                        {"Deception", false},
                                        {"History", false},
                                        {"Insight", false},
                                        {"Intimidation", false},
                                        {"Investigation", false},
                                        {"Medicine", false},
                                        {"Nature", false},
                                        {"Perception", false},
                                        {"Performance", false},
                                        {"Persuasion", false},
                                        {"Religion", false},
                                        {"Sleight of Hand", false},
                                        {"Stealth", false},
                                        {"Survival", false}
                                        }), 
                        choiceNum(choiceNum) {}

                ClassSkillProficiencies()
                        : Proficiencies({
                                        {"Acrobatics", false},
                                        {"Animal Handling", false},
                                        {"Arcana", false},
                                        {"Athletics", false},
                                        {"Deception", false},
                                        {"History", false},
                                        {"Insight", false},
                                        {"Intimidation", false},
                                        {"Investigation", false},
                                        {"Medicine", false},
                                        {"Nature", false},
                                        {"Perception", false},
                                        {"Performance", false},
                                        {"Persuasion", false},
                                        {"Religion", false},
                                        {"Sleight of Hand", false},
                                        {"Stealth", false},
                                        {"Survival", false}
                                        }), 
                        choiceNum(0) {}


                // Getters
                const unsigned int getChoiceNum() const
                {
                        return choiceNum;
                }

                // Setters
                void setChoiceNum(unsigned int newChoiceNum)
                {
                        choiceNum = newChoiceNum;
                }

                // Methods
                // NOTE: need deducter and way to identify the proficiency chosen 
};

class ArmorProficiencies 
{
        protected:
                bool light;
                bool medium;
                bool heavy;
                bool shield;

        public:
                // Constructor
                ArmorProficiencies(bool light, bool medium, bool heavy)
                        : light(light), medium(medium), heavy(heavy) {}

                ArmorProficiencies()
                        : light(false), medium(false), heavy(false) {}

                // Setters
                virtual void setLight(bool value) 
                {
                        light = value;
                }

                virtual void setMedium(bool value) 
                {
                        medium = value;
                }

                virtual void setHeavy(bool value) 
                {
                        heavy = value;
                }

                virtual void setShield(bool value) 
                {
                        shield = value;
                }


                // Getters
                bool isLight() const 
                {
                        return light;
                }

                bool isMedium() const 
                {
                        return medium;
                }

                bool isHeavy() const 
                {
                        return heavy;
                }

                bool isShield() const
                {
                        return shield;
                }
};

class WeaponProficiencies
{
        protected:
                bool simple;
                bool martial;
                bool improvised;

        public:
                // Constructors
                WeaponProficiencies(bool simple, bool martial)
                        : simple(simple), martial(martial), improvised(improvised) {}

                WeaponProficiencies()
                        : simple(false), martial(false), improvised(false) {}

                // Setters
                virtual void setSimple(const bool value)
                {
                        simple = value;
                }

                virtual void setMartial(const bool value)
                {
                        martial = value;
                }

                virtual void setImprovised(const bool value)
                {
                        improvised = value;
                }

                // Getters
                bool isSimple() const
                {
                        return simple;
                }

                bool isMartial() const
                {
                        return martial;
                }

                bool isImprovised() const
                {
                        return improvised;
                }
};


class Features 
{
                unsigned short hitDice;
                unsigned short diceCount;
                unsigned short hitPointsLvl1;
                unsigned short hitPointsPerLvlAlt; // THIS IS THE AVERAGE ROUNDED UP; hitDice/2 + 1;
        public:
                ArmorProficiencies armorProficiencies;
                WeaponProficiencies weaponProficiencies;
                ToolProficiencies toolProficiencies;
                AttributeProficiencies savingThrows; 
                ClassSkillProficiencies skills;

                // Constructor
                Features()
                : hitDice(0), diceCount(0), hitPointsLvl1(0), hitPointsPerLvlAlt(0),
                armorProficiencies(), weaponProficiencies(), toolProficiencies(), 
                savingThrows(), skills() {}
                
                // Setters
                void setHitDice(const unsigned short value)
                {
                        hitDice = value;
                }

                void setDiceCount(const unsigned short value)
                {
                        diceCount = value;
                }

                void setHitPointsLvl1(const unsigned short value)
                {
                        hitPointsLvl1 = value;
                }

                void setHitPointsPerLvlAlt(const unsigned short value)
                {
                        hitPointsPerLvlAlt = value;
                }
                
                // Getters
                unsigned short getHitDice() const
                {
                        return hitDice;
                }

                unsigned short getDiceCount() const
                {
                        return diceCount;
                }

                unsigned short getHitPointsLvl1() const
                {
                        return hitPointsLvl1;
                }

                unsigned short getHitPointsPerLvlAlt() const
                {
                        return hitPointsPerLvlAlt;
                }
};

class Subclass : public Entity 
{
        public:
                Features features;

                // Constructors
                Subclass(string title, string desc)
                        : Entity(title, desc), features() {}

                Subclass(string title)
                        : Entity(title), features() {}
};

class CoreClass : public Subclass
{
        private:
                vector<Subclass> subclasses;
                unsigned short multiClassPrereqLevel;
                vector<string> multiClassPrereqAtts;
                

        public:
                // Constructors
                CoreClass(string title, string desc)
                        : Subclass(title, desc) {}

                CoreClass(string title)
                        : Subclass(title) {}

                // Setters
                void setSubclasses(const vector<Subclass>& newSubclasses)
                {
                        subclasses = newSubclasses;
                }

                void setMultiClassPrereqLevel(const unsigned short newPrereqLevel)
                {
                        multiClassPrereqLevel = newPrereqLevel;
                }

                void setMultiClassPrereqAtts(vector<string>& newPrereqAtts)
                {
                        multiClassPrereqAtts = newPrereqAtts;
                }

                // Getters
                const vector<Subclass> getSubclass() const
                {
                        return subclasses;
                }

                unsigned short getMultiClassPrereqLevel() const 
                {
                        return multiClassPrereqLevel;
                }

                const vector<string>& getMultiClassPrereqAtt() const 
                {
                        return multiClassPrereqAtts;
                }

                // Methods
                void addSubclass(Subclass& subclass)
                {
                        subclasses.push_back(subclass);
                }

                void removeSubclass(string subclass)
                {
                        for (auto it = subclasses.begin(); it != subclasses.end(); )
                        {
                                if (it->getTitle() == subclass)
                                        it = subclasses.erase(it); // returns an element pointing to the next valid position 
                                                                   // after erasure
                                else
                                        ++it;
                        }
                }
};

class SubRace : public Entity
{
        private:
                vector<Entity> additionalTraits;

        public:
                // Constructors
                SubRace(const string& title, const string& desc)
                        : Entity(title, desc) {}

                SubRace(const string& title)
                        : Entity(title) {}

                SubRace()
                        : Entity() {}

                // Setters
                void setAdditionalTraits(const vector<Entity>& newAdditionalTraits)
                {
                        additionalTraits = newAdditionalTraits;
                }

                // Getters
                const vector<Entity>& getAdditionalTraits() const
                {
                        return additionalTraits;
                }

                // Methods
                void addAdditionalTrait(const Entity& additionalTrait)
                {
                        additionalTraits.push_back(additionalTrait);
                }

                void removeAdditionalTrait(string additionalTrait)
                {
                        for (auto it = additionalTraits.begin(); it != additionalTraits.end(); )
                        {
                                if (it->getTitle() == additionalTrait)
                                        it = additionalTraits.erase(it); 
                                else
                                        ++it;
                        }
                }

};

class CoreRace : public SubRace
{
        private:
                vector<SubRace> subraces;
                unordered_map<string, unsigned short> abilityScoreIncrease;
                unsigned short ageOfAdulthood;
                unsigned short lifespan;
                string size;
                unsigned short speed;
                vector<string> languages;

        public:
                // Constructors
                CoreRace(string title, string desc)
                        : SubRace(title, desc),
                        abilityScoreIncrease{
                        {"Strength", 0},
                        {"Dexterity", 0},
                        {"Constitution", 0},
                        {"Intelligence", 0},
                        {"Wisdom", 0},
                        {"Charisma", 0}}, 
                        ageOfAdulthood(0),
                        lifespan(0),
                        size("Blank"),
                        speed(0) {}

                CoreRace(string title)
                        : SubRace(title),
                        abilityScoreIncrease{
                        {"Strength", 0},
                        {"Dexterity", 0},
                        {"Constitution", 0},
                        {"Intelligence", 0},
                        {"Wisdom", 0},
                        {"Charisma", 0}}, 
                        ageOfAdulthood(0),
                        lifespan(0),
                        size("Blank"),
                        speed(0) {}

                CoreRace()
                        : SubRace(),
                        abilityScoreIncrease{
                        {"Strength", 0},
                        {"Dexterity", 0},
                        {"Constitution", 0},
                        {"Intelligence", 0},
                        {"Wisdom", 0},
                        {"Charisma", 0}}, 
                        ageOfAdulthood(0),
                        lifespan(0),
                        size("Blank"),
                        speed(0) {}

                // Setters
                void setSubRaces(const vector<SubRace>& subRaces)
                {
                        subraces = subRaces;
                }

                void setAbilityScoreIncrease(const unordered_map<string, unsigned short>& abilityScores)
                {
                        abilityScoreIncrease = abilityScores;
                }

                void setAgeOfAdulthood(unsigned short age)
                {
                        ageOfAdulthood = age;
                }

                void setLifespan(unsigned short life)
                {
                        lifespan = life;
                }

                void setSize(string& newRaceSize)
                {
                        for (char& c : newRaceSize)
                        {
                                newRaceSize += tolower(c);
                        }

                        if (newRaceSize == "tiny" || newRaceSize == "small" || newRaceSize == "medium" 
                                        || newRaceSize == "large" || newRaceSize == "huge")
                                size = newRaceSize;
                        else
                                throw std::invalid_argument("Invalid size.");
                }

                void setSpeed(unsigned short raceSpeed)
                {
                        speed = raceSpeed;
                }

                void setLanguages(const vector<string>& raceLanguages)
                {
                        languages = raceLanguages;
                }

                // Getters
                const vector<SubRace>& getSubRaces()
                {
                        return subraces;
                }

                const unordered_map<string, unsigned short>& getAbilityScoreIncrease()
                {
                        return abilityScoreIncrease;
                }

                unsigned short getAgeOfAdulthood()
                {
                        return ageOfAdulthood;
                }

                unsigned short getLifespan()
                {
                        return lifespan;
                }

                const string& getSize()
                {
                        return size;
                }

                unsigned short getSpeed()
                {
                        return speed;
                }

                const vector<string>& getLanguages()
                {
                        return languages;
                }

                // Methods
                void addSubrace(SubRace newSubrace)
                {
                        subraces.push_back(newSubrace);
                }

                void removeSubrace(string subrace)
                {
                        for (auto it = subraces.begin(); it != subraces.end(); )
                        {
                                if (it->getTitle() == subrace)
                                        it = subraces.erase(it); 
                                else
                                        ++it;
                        }
                }

                void addLanguage(string newLanguage)
                {
                        languages.push_back(newLanguage);
                }

                void removeLanguage(string language)
                {
                        for (auto it = languages.begin(); it != languages.end(); )
                        {
                                if (*it == language)
                                        it = languages.erase(it); 
                                else
                                        ++it;
                        }
                }
};

class CastingTime
{
        private:
                bool concentration;
                bool action;
                bool bonusAction;
                bool reaction;
                unsigned short combat;
                unsigned short nonCombat;

        public:
                // Constructors
                CastingTime()
                        : concentration(false), action(false), bonusAction(false), reaction(false),
                        combat(0), nonCombat(0) {}

                // Setters
                void setConcentration(const bool value)
                {
                        concentration = value;
                }

                void setAction(const bool value)
                {
                        action = value;
                }

                void setBonusAction(const bool value)
                {
                        bonusAction = value;
                }

                void setReaction(const bool value)
                {
                        reaction = value;
                }

                void setCombatCastingTime(const unsigned short value)
                {
                        combat = value;
                }

                void setNonCombatCastingTime(const unsigned short value)
                {
                        nonCombat = value;
                }

                // Getters
                const bool getConcentration() const
                {
                        return concentration;
                }

                const bool getAction() const
                {
                        return action;
                }

                const bool getBonusAction() const
                {
                        return bonusAction;
                }

                const bool getReaction() const
                {
                        return reaction;
                }

                const unsigned short getCombatCastingTime() const
                {
                        return combat;
                }

                const unsigned short getNonCombatCastingTime() const
                {
                        return nonCombat;
                }
};

class SpellDuration
{
        private:
                unsigned short combat;    // Rounds
                unsigned short nonCombat; // Minutes

        public:
                // Constructor
                SpellDuration() : combat(0), nonCombat(0) {}

                // Setters
                void setCombat(const unsigned short value)
                {
                        combat = value;
                }

                void setNonCombat(const unsigned short value)
                {
                        nonCombat = value; }

                // Getters
                const unsigned short getCombat() const
                {
                        return combat;
                }

                const unsigned short getNonCombat() const
                {
                        return nonCombat;
                }
                
                // Methods
                void min_to_rounds()
                {
                        combat = nonCombat / 10;
                }

                void rounds_to_min()
                {
                        nonCombat = combat * 10;
                }
};

class SpellRange
{
        private:
                bool self;
                bool touch;
                bool cone;
                bool cube;
                bool specialRange;
                unsigned short range; // Feet

        public:
                // Default constructor
                SpellRange()
                        : self(false), touch(false), cone(false), cube(false), 
                        specialRange(false), range(0) {}

                // Setters
                void setSelf(const bool value)
                {
                        self = value;
                }

                void setTouch(const bool value)
                {
                        touch = value;
                }

                void setCone(const bool value)
                {
                        cone = value;
                }

                void setCube(const bool value)
                {
                        cube = value;
                }

                void setSpecialRange(const bool value)
                {
                        specialRange = value;
                }

                void setRange(const unsigned short value)
                {
                        range = value;
                }

                // Getters
                const bool getSelf() const
                {
                        return self;
                }

                const bool getTouch() const
                {
                        return touch;
                }

                const bool getCone() const
                {
                        return cone;
                }

                const bool getCube() const
                {
                        return cube;
                }

                const bool getSpecialRange() const
                {
                        return specialRange;
                }

                const unsigned short getRange() const
                {
                        return range;
                }
};

class SpellComponents
{
        private:
                string somaticComponent;
                string verbalComponent;
                vector<string> materialComponents;
                // Should include amounts; and bool for if material is consumed

        public:
                // Default constructor
                SpellComponents()
                        : somaticComponent("None"), verbalComponent("None") {}

                // Setters
                void setSomaticComponent(const string& component)
                {
                        somaticComponent = component;
                }

                void setVerbalComponent(const string& component)
                {
                        verbalComponent = component;
                }

                void setMaterialComponents(const vector<string>& newMaterialComponents)
                {
                        materialComponents = newMaterialComponents;
                }


                // Getters
                const string getSomaticComponent() const
                {
                        return somaticComponent;
                }

                const string getVerbalComponent() const
                {
                        return verbalComponent;
                }

                const vector<string> getMaterialComponents() const
                {
                        return materialComponents;
                }

                // Methods
                void addMaterialComponent(const string& component)
                {
                        materialComponents.push_back(component);
                }
};

class Spell : public Entity
{
        private:
                unsigned short level;
                vector<string> abilitySavingThrows;
                bool prepared; // Is the spell currently prepared
                bool ritual;

        public:
                CastingTime castingTime;
                SpellDuration duration;
                SpellRange range;
                SpellComponents components;

                // Constructors
                Spell(const string& name)
                        : Entity(name), castingTime(), duration(), range(), components(),
                        level(0), prepared(false), ritual(false) {}

                // Setters
                void setLevel(const unsigned short spellLevel)
                {
                        level = spellLevel;
                }

                void setAbilitySavingThrows(const vector<string>& savingThrows)
                {
                        abilitySavingThrows = savingThrows;
                }

                void setPrepared(const bool isPrepared)
                {
                        prepared = isPrepared;
                }

                void setRitual(const bool isRitual)
                {
                        ritual = isRitual;
                }

                // Getters
                const unsigned short getLevel() const
                {
                        return level;
                }

                const vector<string> getAbilitySavingThrows() const
                {
                        return abilitySavingThrows;
                }

                const bool isPrepared() const
                {
                        return prepared;
                }

                const bool isRitual() const
                {
                        return ritual;
                }

                // Other Methods

                int addAbilitySavingThrow(const string& savingThrow)
                {
                        if (savingThrow.empty())
                                return 1;

                        if (savingThrow == "STR" || savingThrow == "DEX" ||
                                        savingThrow == "CON" || savingThrow == "INT" ||
                                        savingThrow == "WIS" || savingThrow == "CHA")
                        {
                                abilitySavingThrows.push_back(savingThrow);
                                return 0;
                        }

                        return 1;
                }
};

class Feat : public Entity
{
        private:
                string prerequisite;

        public:

                // Constructor

                Feat(string title, string desc, string prereq)
                        : Entity(title, desc), prerequisite(prereq) {}

                Feat(string title, string desc)
                        : Entity(title, desc), prerequisite("Blank") {}

                Feat(string title)
                        : Entity(title), prerequisite("Blank") {}

                Feat()
                        : Entity(), prerequisite("Blank") {}
                
                // Setters
                void setPrerequisite(const string newPrerequisite)
                {
                        prerequisite = newPrerequisite;
                }

                // Getters
                const string getPrerequisite() const
                {
                        return prerequisite;
                }
};

class Skill : public Entity
{
        private:
                bool proficient;

        protected:
                short modifier;

        public:
                // Constructor
                Skill()
                        : Entity(), modifier(0), proficient(false) {}

                Skill(string title)  
                        : Entity(title), modifier((short) 0), proficient(false) {}

                Skill(string title, string desc)  
                        : Entity(title, desc), modifier((short) 0), proficient(false) {}

                Skill(string title, string desc, short modifier)
                        : Entity(title, desc), modifier(modifier), proficient(false) {}

                Skill(string title, string desc, short modifier, bool proficient)
                        : Entity(title, desc), modifier(modifier), proficient(proficient) {}

                // Setters
                void setModifier(const short newModifier)
                {
                        modifier = newModifier;
                }

                void setProficient(const bool newProficient, const unsigned int proficiency)
                {
                        proficient = newProficient;

                        if (proficient == true)
                        {
                                modifier += proficiency;
                        }
                }

                // Getters
                const short getModifier() const
                {
                        return modifier;
                }

                const bool isProficient() const
                {
                        return proficient;
                }
};

class Ability : public Skill
{
        private:
                unsigned short score;

        public:
                vector<Skill> skills;
                // Constructor
                Ability(const string& title)
                        : Skill(title), score(0) {}

                Ability()
                        : Skill(), score(0) {}
                        

                // Setters
                void setScore(const unsigned short abilityScore)
                {
                        score = abilityScore;
                }

                void setSkills(const vector<Skill>& abilitySkills)
                {
                        skills = abilitySkills;
                }

                // Getters
                const unsigned short getScore() const
                {
                        return score;
                }

                const vector<Skill> getSkills() const
                {
                        return skills;
                }

                // Methods
                void calcModifier()
                {
                        modifier = (score - 10) / 2;
                }

                void addSkill(Skill& newSkill)
                {
                        skills.push_back(newSkill);
                }

                void removeSkill(string skill)
                {
                        for (auto it = skills.begin(); it != skills.end(); )
                        {
                                if (it->getTitle() == skill)
                                        it = skills.erase(it); 
                                else
                                        ++it;
                        }
                }
};

class Dice
{
        private: 
                array<const unsigned int, 7> diceTypes = {4, 6, 8, 10, 12, 20, 100};
                unsigned int sides;

        public:
                // Constructor
                Dice(const unsigned short newSides)
                {
                        for (size_t i = 0; i < diceTypes.size(); ++i)
                        {
                                if (sides == diceTypes[i])
                                {
                                        sides = newSides;
                                        break;
                                }
                        else
                                throw std::invalid_argument("Invalid number of sides for the dice.");
                        }
                }
                
                // Methods
                int roll()
                {
                        std::random_device rd;
                        std::mt19937 gen(rd());
                        std::uniform_int_distribution<unsigned short> dis(1, sides);

                        return dis(gen);
                }
                
                string toString()
                {
                        return "D" + std::to_string(sides);
                }
};

class Money
{
        private:
                string unit;
                short amount;

        public:
                // Constructor
                Money(const string& currencyUnit, short currencyAmount)
                        : unit(currencyUnit), amount(currencyAmount) {}
                
                Money()
                        : unit("CP"), amount((short) 0) {}

                // Setters
                void setUnit(const string& currencyUnit)
                {
                        unit = currencyUnit;
                }

                void setAmount(const short currencyAmount)
                {
                        amount = currencyAmount;
                }

                // Getters
                string getUnit() const
                {
                        return unit;
                }

                short getAmount() const
                {
                        return amount;
                }

                // Methods NOTE: Conversion Methods
};

class Item : public Entity
{
        private:
                float weight; // lb
                unsigned short quantity; 
                bool equiped;
        public:
                Money value; 

                // Constructor
                Item(string name, string desc, string unit, unsigned short amount, float weight, unsigned short quantity)
                        :   Entity(name, desc), value(unit, amount), weight(weight), quantity(quantity), equiped(false) {}

                Item(string name, string desc, string unit, unsigned short amount, float weight)
                        :   Entity(name, desc), value(unit, amount), weight(weight), quantity(1), equiped(false) {}

                Item(string name, string desc, string unit, unsigned short amount)
                        :   Entity(name, desc), value(unit, amount), weight(0), quantity(1), equiped(false) {}

                Item(string name, string desc)
                        :   Entity(name, desc), value(), weight(0), quantity(1), equiped(false) {}

                Item(string name)
                        :   Entity(name), value(), weight(0), quantity(1), equiped(false) {}

                Item()
                        :   Entity(), value(), weight(0), quantity(1), equiped(false) {}

                // Getters
                double getWeight() const
                {
                        return weight;
                }

                double getQuantity() const
                {
                        return quantity;
                }

                bool isEquiped() const
                {
                        return equiped;
                }

                // Setters
                void setWeight(const float newWeight)
                {
                        weight = newWeight;
                }

                void setQuantity(const unsigned short newQuantity)
                {
                        quantity = newQuantity;
                }

                void setEquiped(const bool newEquiped)
                {
                        equiped = newEquiped;
                }
};

class Weapon : public Item, public WeaponProficiencies
{
        private:
                unsigned short damageDice; // e.g. 6 = D6
                unsigned short diceCount;
                string physicalDamageType;

                bool melee;
                bool ranged;
                bool magical;
                bool silvered;

                bool ammunition;
                bool finesse;
                bool heavy;
                bool light;
                bool loading;
                bool reach;
                bool special;
                bool thrown;
                bool twoHanded;
                bool versatile;

                array<unsigned short, 2> range;
                string ammoType;
                unsigned short ammoCount;

                unsigned short versatileDamageDice; 
                unsigned short versatileDiceCount;

        public:
                // Constructor
                Weapon(string name)
                        : Item(name), WeaponProficiencies(),  damageDice(0), diceCount(0), 
                        physicalDamageType("Blank"), melee(false), ranged(false), 
                        magical(false), silvered(false), ammunition(false), finesse(false), heavy(false), 
                        light(false), loading(false), reach(false), special(false), thrown(false), 
                        twoHanded(false), versatile(false), range{0, 0}, ammoType("Blank"), ammoCount(0),  
                        versatileDamageDice(0), versatileDiceCount(0) {}
                
                // Setters
                
                void setSimple(const bool value) override 
                {
                        simple = value;
                        if (simple == true)
                        {
                                martial = false;
                                improvised = false;
                        }
                }

                void setMartial(const bool value) override
                {
                        martial = value;
                        if (martial == true)
                        {
                                simple = false;
                                improvised = false;
                        }
                }

                void setImprovised(const bool value) override
                {
                        improvised = value;

                        if (improvised == true)
                        {
                                simple = false;
                                martial = false;
                        }
                }

                void setDamageDice(unsigned short newDamageDice)
                {
                        damageDice = newDamageDice;
                }

                void setDiceCount(unsigned short newDiceCount)
                {
                        diceCount = newDiceCount;
                }

                void setPhysicalDamageType(const string& newPhysicalDamageType)
                {
                        string lowercaseType;
                        for (const char& c : newPhysicalDamageType)
                        {
                                lowercaseType += tolower(c);
                        }

                        if (lowercaseType == "bludgeoning" || lowercaseType == "piercing" || lowercaseType == "slashing")
                        {
                                physicalDamageType = lowercaseType;
                        }
                }

                void setSilvered(const bool newSilvered)
                {
                        silvered = newSilvered;
                }

                void setMelee(const bool newMelee)
                {
                        melee = newMelee;
                }

                void setRanged(const bool newRanged)
                {
                        ranged = newRanged;
                }

                void setMagical(const bool newMagical)
                {
                        magical = newMagical;
                }

                void setAmmunition(const bool newAmmunition)
                {
                        ammunition = newAmmunition;
                }

                void setFinesse(const bool newFinesse)
                {
                        finesse = newFinesse;
                }

                void setHeavy(const bool newHeavy)
                {
                        heavy = newHeavy;

                        if (heavy == true)
                                light = false;
                }

                void setLight(const bool newLight)
                {
                        light = newLight;
                }

                void setLoading(const bool newLoading)
                {
                        loading = newLoading;
                }

                void setReach(const bool newReach)
                {
                        reach = newReach;
                }

                void setSpecial(const bool newSpecial)
                {
                        special = newSpecial;
                }

                void setThrown(const bool newThrown)
                {
                        thrown = newThrown;
                }

                void setTwoHanded(const bool newTwoHanded)
                {
                        twoHanded = newTwoHanded;
                }

                void setVersatile(const bool newVersatile)
                {
                        versatile = newVersatile;
                }

                void setRange(const array<unsigned short, 2>& newRange)
                {
                        range = newRange;
                }

                void setAmmoType(const string& newAmmoType)
                {
                        ammoType = newAmmoType;
                }

                void setAmmoCount(unsigned short newAmmoCount)
                {
                        ammoCount = newAmmoCount;
                }

                void setVersatileDamageDice(unsigned short damageDice) 
                {
                        versatileDamageDice = damageDice;
                }

                void setVersatileDiceCount(unsigned short diceCount) 
                {
                        versatileDiceCount = diceCount;
                }

                // Getters
                unsigned short getDamageDice() const
                {
                        return damageDice;
                }

                unsigned short getDiceCount() const
                {
                        return diceCount;
                }

                string getPhysicalDamageType() const
                {
                        return physicalDamageType;
                }

                bool isSilvered() const
                {
                        return silvered;
                }

                bool isMelee() const
                {
                        return melee;
                }

                bool isRanged() const
                {
                        return ranged;
                }

                bool isMagical() const
                {
                        return magical;
                }

                array<unsigned short, 2> getRange() const
                {
                        return range;
                }

                string getAmmoType() const
                {
                        return ammoType;
                }

                unsigned short getAmmoCount() const
                {
                        return ammoCount;
                }

                bool hasAmmunition() const
                {
                        return ammunition;
                }

                bool isFinesse() const
                {
                        return finesse;
                }

                bool isHeavy() const
                {
                        return heavy;
                }

                bool isLight() const
                {
                        return light;
                }

                bool isLoading() const
                {
                        return loading;
                }

                bool hasReach() const
                {
                        return reach;
                }

                bool isSpecial() const
                {
                        return special;
                }

                bool isThrown() const
                {
                        return thrown;
                }

                bool isTwoHanded() const
                {
                        return twoHanded;
                }

                bool isVersatile() const
                {
                        return versatile;
                }

                unsigned short getVersatileDamageDice() const 
                {
                        return versatileDamageDice;
                }


                unsigned short getVersatileDiceCount() const 
                {
                        return versatileDiceCount;
                }

};

class Armor : public Item, public ArmorProficiencies
{
        private:
                unsigned short AC;
                bool stealthDisadvantage;
                unsigned short strengthRequirement;

        public:
                // Constructors
                Armor(string name) 
                        :  Item(name), ArmorProficiencies(), AC(0), 
                        stealthDisadvantage(false), strengthRequirement(0) {}

                // Setters
                void setLight(bool value) override
                {
                        light = value;
                        if (light == true)
                        {
                                if (medium == true)
                                        medium = false;

                                if (heavy == true)
                                        heavy = false;

                                if (shield == true)
                                        shield = false;
                        }
                }

                void setMedium(bool value) override
                {
                        medium = value;
                        if (medium == true)
                        {
                                if (light == true)
                                        light = false;

                                if (heavy == true)
                                        heavy = false;

                                if (shield == true)
                                        shield = false;
                        }
                }

                void setHeavy(bool value) override
                {
                        heavy = value;
                        if (heavy == true)
                        {
                                if (light == true)
                                        light = false;

                                if (medium == true)
                                        medium = false;

                                if (shield == true)
                                        shield = false;
                        }
                }

                void setShield(bool value) override
                {
                        shield = value;
                        if (shield == true)
                        {
                                if (light == true)
                                        light = false;

                                if (medium == true)
                                        medium = false;

                                if (heavy == true)
                                        heavy = false;
                        }
                }

                void setAC(unsigned short newAC) 
                {
                        AC = newAC;
                }

                void setStealthDisadvantage(bool value) 
                {
                        stealthDisadvantage = value;
                }

                void setStrengthRequirement(unsigned short newStrengthRequirement) 
                {
                        strengthRequirement = newStrengthRequirement;
                }

                // Getters

                bool isLight() const 
                {
                        return light;
                }

                bool isMedium() const 
                {
                        return medium;
                }

                bool isHeavy() const 
                {
                        return heavy;
                }

                unsigned short getAC() const 
                {
                        return AC;
                }

                bool hasStealthDisadvantage() const 
                {
                        return stealthDisadvantage;
                }

                unsigned short getStrengthRequirement() const 
                {
                        return strengthRequirement;
                }
};

class Gear
{
        public:
                vector<Weapon> weapons;
                vector<Armor> armor;
                vector<Item> items;
};

class Character
{
        private:
                // Constants 
                static constexpr size_t ABILITY_COUNT = 6;

                string name;
                unsigned short level;
                string alignment;
                string background;
                // MAGIC CLASSES SHOULD HAVE ARCANE

                unsigned short proficiencyModifier;
                unsigned short passivePerception;
                unsigned short passiveInsight;
                bool inspiration;

                unsigned short armorClass;
                unsigned short initiative;
                unsigned short speed;
                unsigned short maxHP;
                unsigned int currentHP;
                // method where you enter the amount of damage you take and deduce from hp

                vector<Entity> languages;

                Ability str, dex, con, intel, wis, cha;
                Skill athletics, acrobatics, sleightOfHand, stealth, arcana, history, investigation, 
                      nature, religion, animalHandling, insight, medecine, perception, survival, deception, 
                      intimidation, performance, persuasion;

                // Integrate into constuctor

        public:
                // Public Vars
                CoreRace race;
                CoreClass starterClass;
                vector <CoreClass> classes;

                ArmorProficiencies armorProficiencies;
                WeaponProficiencies weaponProficiencies;
                ToolProficiencies toolProficiencies;

                vector<Spell> spells;
                vector<Feat> feats;

                array<array<bool, 5>, 9> spellSlots;

                // Constructor
                Character() :
                        name("Blank"), level(1), alignment("Blank"), background("Blank"), proficiencyModifier(0), 
                        passivePerception(0), passiveInsight(0), inspiration(false), armorClass(0), 
                        initiative(0), speed(0), maxHP(0), currentHP(0), str(), dex(), intel(), wis(), cha(), 
                        race(), starterClass("Title"),  classes({starterClass}), armorProficiencies(), 
                        weaponProficiencies(), toolProficiencies()
                        {
                                str.setSkills({athletics});
                                dex.setSkills({acrobatics, sleightOfHand, stealth});
                                intel.setSkills({arcana, history, investigation, nature, religion});
                                wis.setSkills({animalHandling, insight, medecine, perception, survival});
                                cha.setSkills({deception, intimidation, performance, persuasion});
                        }
                
                // Setters
                void setName(const string& newName) 
                {
                        name = newName;
                }

                void setLevel(unsigned short newLevel) 
                {
                        level = newLevel;
                }

                void setAlignment(const string& newAlignment) 
                {
                        alignment = newAlignment;
                }

                void setBackground(const string& newBackground) 
                {
                        background = newBackground;
                }

                void setProficiencyModifier(unsigned short newModifier) 
                {
                        proficiencyModifier = newModifier;
                }

                void setPassivePerception(unsigned short newPerception) 
                {
                        passivePerception = newPerception;
                }

                void setPassiveInsight(unsigned short newInsight) 
                {
                        passiveInsight = newInsight;
                }

                void setInspiration(bool newInspiration) 
                {
                        inspiration = newInspiration;
                }

                void setArmorClass(unsigned short newArmorClass) 
                {
                        armorClass = newArmorClass;
                }

                void setInitiative(unsigned short newInitiative) 
                {
                        initiative = newInitiative;
                }

                void setSpeed(unsigned short newSpeed) 
                {
                        speed = newSpeed;
                }

                void setMaxHP(unsigned short newMaxHP) 
                {
                        maxHP = newMaxHP;
                }

                void setCurrentHP(unsigned int newCurrentHP) 
                {
                        currentHP = newCurrentHP;
                }

                void setLanguages(const vector<Entity>& newLanguages) 
                {
                        languages = newLanguages;
                }

                // Getters
                string getName() const 
                {
                        return name;
                }

                unsigned short getLevel() const 
                {
                        return level;
                }

                string getAlignment() const 
                {
                        return alignment;
                }

                string getBackground() const 
                {
                        return background;
                }

                unsigned short getProficiencyModifier() const 
                {
                        return proficiencyModifier;
                }

                unsigned short getPassivePerception() const 
                {
                        return passivePerception;
                }

                unsigned short getPassiveInsight() const 
                {
                        return passiveInsight;
                }

                bool hasInspiration() const 
                {
                        return inspiration;
                }

                unsigned short getArmorClass() const 
                {
                        return armorClass;
                }

                unsigned short getInitiative() const 
                {
                        return initiative;
                }

                unsigned short getSpeed() const 
                {
                        return speed;
                }

                unsigned short getMaxHP() const 
                {
                        return maxHP;
                }

                unsigned int getCurrentHP() const 
                {
                        return currentHP;
                }

                vector<Entity> getLanguages() const 
                {
                        return languages;
                }
};

int main()
{
        // Armor
        Armor chainMail("Chain Mail");
        chainMail.setMedium(true); // Need a way to calculate that this is AC + Dex
        chainMail.value.setUnit("gp");
        chainMail.value.setAmount(50);
        chainMail.setAC(14);
        chainMail.setStealthDisadvantage(true);
        chainMail.setWeight(45);

        Armor leatherArmor("Leather");
        leatherArmor.setLight(true); 
        leatherArmor.value.setUnit("gp");
        leatherArmor.value.setAmount(10);
        leatherArmor.setAC(11);
        leatherArmor.setWeight(10);

        // Martial Weapons
        Weapon shortsword("Short Sword");
        shortsword.setMartial(true);
        shortsword.value.setUnit("gp");
        shortsword.value.setAmount(10);
        shortsword.setDamageDice(6);
        shortsword.setDiceCount(1);
        shortsword.setPhysicalDamageType("piercing");
        shortsword.setWeight(2);
        shortsword.setFinesse(true);
        shortsword.setLight(true);

        Weapon longbow("Longbow");
        longbow.setMartial(true);
        longbow.value.setUnit("gp");
        longbow.value.setAmount(50);
        longbow.setDamageDice(8);
        longbow.setDiceCount(1);
        longbow.setPhysicalDamageType("piercing");
        longbow.setWeight(2);
        longbow.setAmmunition(true);
        longbow.setHeavy(true);
        longbow.setTwoHanded(true);
        longbow.setRange({150, 600});

        // Simple Weapons
        Weapon club("Club");
        club.value.setUnit("sp");
        club.value.setAmount(1);
        club.setWeight(2);
        club.setSimple(true);
        club.setDamageDice(6);
        club.setDiceCount(1);
        club.setPhysicalDamageType("bludgeoning");
        club.setMelee(true);
        club.setRange({0, 0});

        Weapon dagger("Dagger");
        dagger.value.setUnit("gp");
        dagger.value.setAmount(2);
        dagger.setWeight(1);
        dagger.setSimple(true);
        dagger.setDamageDice(4);
        dagger.setDiceCount(1);
        dagger.setPhysicalDamageType("piercing");
        dagger.setMelee(true);
        dagger.setFinesse(true);
        dagger.setThrown(true);
        dagger.setRange({20, 60});
        dagger.setAmmoType("None");

        Weapon greatclub("Greatclub");
        greatclub.value.setUnit("sp");
        greatclub.value.setAmount(2);
        greatclub.setWeight(10);
        greatclub.setSimple(true);
        greatclub.setDamageDice(8);
        greatclub.setDiceCount(1);
        greatclub.setPhysicalDamageType("bludgeoning");
        greatclub.setMelee(true);
        greatclub.setTwoHanded(true);
        greatclub.setRange({0, 0});

        Weapon handaxe("Handaxe");
        handaxe.value.setUnit("gp");
        handaxe.value.setAmount(5);
        handaxe.setWeight(2);
        handaxe.setSimple(true);
        handaxe.setDamageDice(6);
        handaxe.setDiceCount(1);
        handaxe.setPhysicalDamageType("slashing");
        handaxe.setMelee(true);
        handaxe.setThrown(true);
        handaxe.setRange({20, 60});
        handaxe.setAmmoType("None");

        Weapon javelin("Javelin");
        javelin.value.setUnit("sp");
        javelin.value.setAmount(5);
        javelin.setWeight(2);
        javelin.setSimple(true);
        javelin.setDamageDice(6);
        javelin.setDiceCount(1);
        javelin.setPhysicalDamageType("piercing");
        javelin.setMelee(true);
        javelin.setThrown(true);
        javelin.setRange({30, 120});
        javelin.setAmmoType("None");

        Weapon lightHammer("Light hammer");
        lightHammer.value.setUnit("gp");
        lightHammer.value.setAmount(2);
        lightHammer.setWeight(2);
        lightHammer.setSimple(true);
        lightHammer.setDamageDice(4);
        lightHammer.setDiceCount(1);
        lightHammer.setPhysicalDamageType("bludgeoning");
        lightHammer.setMelee(true);
        lightHammer.setThrown(true);
        lightHammer.setRange({20, 60});
        lightHammer.setAmmoType("None");

        Weapon mace("Mace");
        mace.value.setUnit("gp");
        mace.value.setAmount(5);
        mace.setWeight(4);
        mace.setSimple(true);
        mace.setDamageDice(6);
        mace.setDiceCount(1);
        mace.setMelee(true);
        mace.setPhysicalDamageType("bludgeoning");
        mace.setRange({0, 0});

        Weapon quarterstaff("Quarterstaff");
        quarterstaff.value.setUnit("sp");
        quarterstaff.value.setAmount(2);
        quarterstaff.setWeight(4);
        quarterstaff.setSimple(true);
        quarterstaff.setDamageDice(6);
        quarterstaff.setDiceCount(1);
        quarterstaff.setPhysicalDamageType("bludgeoning");
        quarterstaff.setMelee(true);
        quarterstaff.setVersatile(true);
        quarterstaff.setRange({0, 0});

        Weapon sickle("Sickle");
        sickle.value.setUnit("gp");
        sickle.value.setAmount(1);
        sickle.setWeight(2);
        sickle.setSimple(true);
        sickle.setDamageDice(4);
        sickle.setDiceCount(1);
        sickle.setPhysicalDamageType("slashing");
        sickle.setMelee(true);
        sickle.setRange({0, 0});

        Weapon spear("Spear");
        spear.value.setUnit("gp");
        spear.value.setAmount(1);
        spear.setWeight(3);
        spear.setSimple(true);
        spear.setDamageDice(6);
        spear.setDiceCount(1);
        spear.setPhysicalDamageType("piercing");
        spear.setMelee(true);
        spear.setThrown(true);
        spear.setVersatile(true);
        spear.setRange({20, 60});
        spear.setAmmoType("None");
        spear.setVersatileDamageDice(8);
        spear.setVersatileDiceCount(1);

        array<Weapon, 10> simpleWeapons = {club, dagger, greatclub, handaxe, javelin,
                lightHammer, mace, quarterstaff, sickle, spear};

        // Items
        Item backpack("Backpack");
        backpack.value.setUnit("gp");
        backpack.value.setAmount(2);
        backpack.setWeight(5);
        backpack.setDesc("A backpack is a leather pack carried on the back, typically with straps to secure it." 
                        "A backpack can hold 1 cubic foot/ 30 pounds of gear.\nYou can also strap items, such as" 
                        "a bedroll or a coil of rope, to the outside of a backpack.");

        Item crowbar("Crowbar");
        crowbar.value.setUnit("gp");
        crowbar.value.setAmount(2);
        crowbar.setWeight(5);
        crowbar.setDesc("Using a crowbar grants advantage to Strength checks where the crowbar's leverage can be applied.");

        Item hammer("Hammer");
        hammer.value.setUnit("gp");
        hammer.value.setAmount(1);
        hammer.setWeight(3);
        hammer.setDesc("This one-handed hammer with an iron head is useful for pounding pitons into a wall.");

        Item piton("Piton");
        piton.value.setUnit("cp");
        piton.value.setAmount(5);
        piton.setWeight(0.25);
        piton.setDesc("When a wall doesn’t offer handholds and footholds, you can make your own." 
                        "A piton is a steel spike with an eye through which you can loop a rope.");

        Item torch("Torch");
        torch.value.setUnit("cp");
        torch.value.setAmount(1);
        torch.setWeight(1);
        torch.setDesc("A torch burns for 1 hour, providing bright light in a 20-foot radius and dim" 
                        "light for an additional 20 feet. If you make a melee attack with a burning "  
                        "torch and hit, it deals 1 fire damage.");

        Item tinderbox("Tinderbox");
        tinderbox.value.setUnit("sp");
        tinderbox.value.setAmount(5);
        tinderbox.setWeight(1);
        tinderbox.setDesc("This small container holds flint, fire steel, and tinder (usually dry cloth" 
                        "soaked in light oil) used to kindle a fire. Using it to light a torch — or anything "  
                        "else with abundant, exposed fuel — takes an action. Lighting any other fire takes 1 minute.");

        Item ration("Ration");
        ration.value.setUnit("sp");
        ration.value.setAmount(5);
        ration.setWeight(2);
        ration.setDesc("Consists of dry foods suitable for extended travel, including jerky, " 
                        "dried fruit, hardtack, and nuts.");

        Item waterskin("Waterskin");
        waterskin.value.setUnit("sp");
        waterskin.value.setAmount(2);
        waterskin.setWeight(5);
        waterskin.setDesc("A waterskin is a leather pouch that can hold up to 4 pints of liquid, typically water.");

        Item rope("Hempen Rope");
        rope.value.setUnit("gp");
        rope.value.setAmount(1);
        rope.setWeight(10);
        rope.setDesc("Rope is essential for climbing, descending, and securing items." );

        Item bedroll("Bedroll");
        bedroll.value.setUnit("gp");
        bedroll.value.setAmount(1);
        bedroll.setWeight(7);
        bedroll.setDesc("A bedroll consists of a blanket and a sleeping pad rolled together."
                        "It provides some comfort and insulation when sleeping outdoors.");

        Item messKit("Mess Kit");
        messKit.value.setUnit("sp");
        messKit.value.setAmount(2);
        messKit.setWeight(1);
        messKit.setDesc("A mess kit includes a plate, bowl, cup, and utensils necessary for eating" 
                        " meals while adventuring. It is lightweight and designed for portability.");

        // Quantity
        piton.setQuantity(10);
        torch.setQuantity(10);
        ration.setQuantity(10);

        // Packs
        array<Item, 9> dungeoneersPack = {backpack, crowbar, hammer, piton, torch, tinderbox, ration, waterskin, rope};
        array<Item, 9> explorersPack = {backpack, bedroll, torch, tinderbox, ration, waterskin, rope};

        // Ranger Class
        CoreClass ranger("Ranger");
        ranger.features.setHitDice(10);
        ranger.features.setDiceCount(1);
        ranger.features.setHitPointsPerLvlAlt(6);
        ranger.features.armorProficiencies.setLight(true);
        ranger.features.armorProficiencies.setMedium(true);
        ranger.features.armorProficiencies.setShield(true);
        ranger.features.weaponProficiencies.setSimple(true);
        ranger.features.weaponProficiencies.setMartial(true);
        // no tool proficiencies

        try
        {
                ranger.features.savingThrows.setProficiency("Strength", true);
                ranger.features.savingThrows.setProficiency("Dexterity", true);
                ranger.features.skills.setChoiceNum(3);
                ranger.features.skills.setProficiency("Animal Handling", true);
                ranger.features.skills.setProficiency("Athletics", true);
                ranger.features.skills.setProficiency("Insight", true);
                ranger.features.skills.setProficiency("Investigation", true);
                ranger.features.skills.setProficiency("Nature", true);
                ranger.features.skills.setProficiency("Perception", true);
                ranger.features.skills.setProficiency("Stealth", true);
                ranger.features.skills.setProficiency("Survival", true);
        }
        catch (const std::exception &ex)
        {
                cout << "Exception Caught: " << ex.what() << endl;
        }

}
