












#pragma once

#ifndef __CTP_GOAL_H__
#define __CTP_GOAL_H__ 1


#include "Goal.h"
#include "MapPoint.h"
#include "Army.h"
#include "Unit.h"

class CTPGoal;
class CTPAgent;
typedef CTPGoal* CTPGoal_ptr;
typedef CTPAgent* CTPAgent_ptr;

class CTPGoal : public Goal { 

	enum SUB_TASK_TYPE 
	{
		SUB_TASK_GOAL,
		SUB_TASK_RALLY,
		SUB_TASK_TRANSPORT_TO_BOARD,
		SUB_TASK_CARGO_TO_BOARD,
		SUB_TASK_AIRLIFT
	};

public:

	
    CTPGoal(); 	

	
	virtual ~CTPGoal();

	
	bool operator==(const CTPGoal & rval) const;

	
	bool operator<(const CTPGoal & rval) const;

	
	
    void Init();

	
    void Set_Target_Pos(const MapPoint & pos);

	
    void Set_Target_Army(const Army & army);

	
    void Set_Target_City(const Unit & city);

	
	const MapPoint Get_Target_Pos(const Army & army) const;

	
    const MapPoint & Get_Target_Pos() const;

	
    const Army & Get_Target_Army() const;

	
    const Unit & Get_Target_City() const;

	
	sint32 Get_Target_Value() const;

	
	PLAYER_INDEX Get_Target_Owner() const;

	
	
	Agent_ptr Rollback_Agent(Agent_List::const_iterator & agent_iter);

	
	
	
	bool Is_Execute_Incrementally() const;

  	
  	
  	void Compute_Needed_Troop_Flow();

  	
  	
  	
  	Utility Compute_Matching_Value( const Agent_ptr agent ) const;

  	
  	
  	
  	Utility Compute_Raw_Priority();

	
	
	

	
	GOAL_RESULT Execute_Task();

	
	bool Get_Totally_Complete() const;

	
	bool Get_Invalid() const;

	
	bool Get_Removal_Time() const;

	
	bool Pretest_Bid(const Agent_ptr agent_ptr) const;

	
	bool Pretest_Bid(const Agent_ptr agent_ptr, const MapPoint & cache_pos) const;

	
	bool ArmiesAtGoal() const;

	
	sint32 GetThreatenBonus() const;

	
	
	

	
	bool ReferencesAgent(const CTPAgent *ctp_agent) const;

    
    void Log_Debug_Info(const int &log) const;

protected:

	
	
	
	
	
	
	bool NeededForGarrison(CTPAgent_ptr army, 
				           const MapPoint &dest_pos,
						   sint8 & garrison_count,
						   double & garrison_strength) const;

	
	
	bool FindPathToTask(CTPAgent_ptr the_army, 
						const MapPoint & goal_pos, 
						const SUB_TASK_TYPE & sub_task,
						Path & found_path);

	bool FollowPathToTask( CTPAgent_ptr first_army, 
						   CTPAgent_ptr second_army, 
						   const SUB_TASK_TYPE sub_task, 
						   const MapPoint &dest_pos,
						   const Path & path);



	
	bool GotoTransportTaskSolution(CTPAgent_ptr the_army, CTPAgent_ptr the_transport, const SUB_TASK_TYPE & sub_task);

	
	bool GotoGoalTaskSolution(CTPAgent_ptr the_army, const MapPoint & goal_pos, const SUB_TASK_TYPE & sub_task);

	
	bool GotoTaskSolution(CTPAgent_ptr agent_ptr, const SUB_TASK_TYPE & sub_task, const MapPoint & goal_pos);

	
	
	

	
	bool Ok_To_Rally() const;

	
	bool RallyComplete() const;

	
	
	bool RallyTroops();

	
	bool Goal_Too_Expensive() const;

	
	
	

	
	bool TryTransport(CTPAgent_ptr agent_ptr, const MapPoint & goal_pos);

	
	
	bool FindTransport(const CTPAgent_ptr & agent_ptr, CTPAgent_ptr & transport_ptr);

	
	
	bool LoadTransport(CTPAgent_ptr agent_ptr, CTPAgent_ptr transport_ptr);

	
	
	

	
	MapPoint m_target_pos;
	Unit m_target_city;
	Army m_target_army;
}; 






#endif __CTP_GOAL_H__