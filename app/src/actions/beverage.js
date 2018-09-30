import { WEBSOCKET_SEND } from '../util';

export const brewBeverage = id => dispatch => dispatch({ type: WEBSOCKET_SEND, payload: { beverageId: id }});