import { createWebsocketSendAction } from '../util';

export const motorOff = id => dispatch => dispatch(createWebsocketSendAction({ command: 'motor_off', id }));

export const motorLoad = id => dispatch => dispatch(createWebsocketSendAction({ command: 'motor_on_load', id }));

export const motorUnload = id => dispatch => dispatch(createWebsocketSendAction({ command: 'motor_on_unload', id }));