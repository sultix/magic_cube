/*
 * State.h
 *
 *  Created on: Dec 29, 2016
 *      Author: alex
 */

#ifndef STATE_H_
#define STATE_H_

class State {
public:
	State();
	virtual ~State();

protected:
	void onEntry(void);
	void onExit(void);
};

#endif /* STATE_H_ */
