import { createWebsocketSendAction } from '../util';

export const CONTROLS_OPENED = 'CONTROLS_OPENED';
export const CONTROLS_CLOSED = 'CONTROLS_CLOSED';

export const motorOff = id => dispatch => dispatch(createWebsocketSendAction('off_' + id));

export const motorLoad = id => dispatch => dispatch(createWebsocketSendAction('load_' + id));

export const motorUnload = id => dispatch => dispatch(createWebsocketSendAction('unload_' + id));

export const motorOffAll = () => dispatch => dispatch(createWebsocketSendAction('off_all'));

export const openControls = () => dispatch => dispatch({ type: CONTROLS_OPENED, payload: undefined });

export const closeControls = () => dispatch => dispatch({ type: CONTROLS_CLOSED, payload: undefined });